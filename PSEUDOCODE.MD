============================================================
PROJECT: CSC-252 Assignment 5 - Group Project
GROUP: Karon Eley, Andre Gonzalez, Calvin Hart, Robert Wilson
DATE: 25 April 2026
============================================================

1. PROGRAM OVERVIEW
-------------------
This program generates 500 random integers between 0 and 999,
saves them to a binary file, reads them back into memory, and
runs four different analyses on the data: Search, Statistics,
Duplicates, and Missing Values. Sorting is done using
Selection Sort, and searching uses a recursive Binary Search.


2. DATA INPUT/OUTPUT (BinaryIO)
-------------------------------
FUNCTION writeBinary(filename, valuesArray, length):
    Open the file in binary write mode
    Write all integer bytes from the array directly to the file
    Close the file

CLASS BinaryReader:
    Private variables: data (integer pointer), size (integer)

    CONSTRUCTOR(filename):
        Set data to null and size to 0
        Call readValues(filename)

    FUNCTION readValues(filename):
        Open file in binary mode, jump to the end to find total size
        Calculate number of integers = total bytes / size of one integer
        Jump back to the beginning of the file
        Allocate a new integer array of that size
        Read all bytes from the file into the array
        Close the file

    FUNCTION getValues(): return data array
    FUNCTION getSize(): return size

    DESTRUCTOR: free the dynamically allocated data array


3. SORTING AND SEARCHING (SortSearch)
--------------------------------------
FUNCTION selection_sort(valuesArray, size):
    For i from 0 to size - 2:
        Assume position i holds the minimum value
        For j from i+1 to size - 1:
            If valuesArray[j] is less than current minimum:
                Update minimum index to j
        Swap the value at the minimum index with the value at index i

FUNCTION binary_search(valuesArray, key, size):
    Call binary_search_recursive with start = 0, end = size - 1
    Return the result (true or false)

FUNCTION binary_search_recursive(valuesArray, key, start, end):
    If start is greater than end:
        Return false (key not found)
    Calculate mid = start + (end - start) / 2
    If valuesArray[mid] equals key:
        Return true
    If valuesArray[mid] is greater than key:
        Search the left half (start to mid - 1)
    Otherwise:
        Search the right half (mid + 1 to end)


4. ANALYZERS
------------
BASE CLASS Analyzer:
    Protected variables: values (integer pointer), size (integer)
    
    CONSTRUCTOR(values, size):
        Clone the input array using cloneValues() and store it
    
    FUNCTION cloneValues(source, size):
        Allocate a new array of the same size
        Copy each element from source into the new array
        Return the new array
    
    DESTRUCTOR: delete the cloned values array
    
    PURE VIRTUAL FUNCTION analyze() -- must be implemented by subclasses

CLASS SearchAnalyzer (extends Analyzer):
    CONSTRUCTOR(values, size):
        Call Analyzer constructor to clone and store data
        Call selection_sort() on the stored array

    FUNCTION analyze():
        Set found = 0
        Repeat 100 times:
            Generate a random integer between 0 and 999
            If binary_search finds that number in the array:
                Increment found
        Return a string reporting how many values were found

CLASS StatisticsAnalyser (extends Analyzer):
    CONSTRUCTOR(values, size):
        Call Analyzer constructor to clone and store data
        Call selection_sort() on the stored array

    FUNCTION analyze():
        If size is 0, return "No values to analyze"
        Min = first element (index 0) since array is sorted
        Max = last element (index size - 1) since array is sorted
        If size is odd:
            Median = middle element
        If size is even:
            Median = average of the two middle elements
        
        Find Mode:
            Walk through the sorted array
            Track the current value and how many times it appears in a row
            When the value changes, check if the previous count was
              higher than the current best -- if so, update mode
        Return a string with Min, Max, Median, and Mode

CLASS DuplicatesAnalyser (extends Analyzer):
    CONSTRUCTOR(values, size):
        Call Analyzer constructor to clone and store data
        Call selection_sort() on the stored array

    FUNCTION analyze():
        Set duplicateCount = 0
        For i from 1 to size - 1:
            If valuesArray[i] equals valuesArray[i - 1]:
                Increment duplicateCount
                Skip forward past any additional matching values
        Return a string reporting the number of duplicate values found

CLASS MissingAnalyser (extends Analyzer):
    CONSTRUCTOR(values, size):
        Call Analyzer constructor to clone and store data
        Call selection_sort() on the stored array

    FUNCTION analyze():
        Set missingCount = 0
        For every integer i from 0 to 999:
            If binary_search does NOT find i in the array:
                Increment missingCount
        Return a string reporting how many numbers from 0-999 are missing


5. MAIN PROGRAM FLOW (main.cpp)
--------------------------------
START
    Seed the random number generator with the current time
    Set filename = "data.bin"

    Create an array of 500 integers
    Fill it with random values between 0 and 999
    Call writeBinary to save the array to the file

    Create a BinaryReader to read the file back into memory
    Get the values array and size from the reader

    Create a SearchAnalyzer with the values and size
    Create a StatisticsAnalyser with the values and size
    Create a DuplicatesAnalyser with the values and size
    Create a MissingAnalyser with the values and size

    Print the result of SearchAnalyzer.analyze()
    Print the result of StatisticsAnalyser.analyze()
    Print the result of DuplicatesAnalyser.analyze()
    Print the result of MissingAnalyser.analyze()
END