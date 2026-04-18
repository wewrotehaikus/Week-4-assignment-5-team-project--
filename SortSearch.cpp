/* ---------------------------------------------------------------------------
** I attest that this following code represents my own work and is subject to
** the plagiarism policy found in the course syllabus.
**
**       Class: CSC 252 - Programming in C++
**  Assignment: Assignment 5
**        File: SortSearch.cpp
** Description: 
**      Author: Karon Eley, Andre Gonzalez, Calvin Hart, Robert Wilson
**        Date: 09 April 26
** -------------------------------------------------------------------------*/

#include "SortSearch.h"

void selection_sort(int* values, int size) {
    for (int i = 0; i < size - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < size; ++j) {
            if (values[j] < values[min_idx]) min_idx = j;
        }
        int temp = values[min_idx];
        values[min_idx] = values[i];
        values[i] = temp;
    }
}

bool binary_search_recursive(int* values, int key, int start, int end) {
    if (start > end) return false;
    int mid = start + (end - start) / 2;
    if (values[mid] == key) return true;
    if (values[mid] > key) return binary_search_recursive(values, key, start, mid - 1);
    return binary_search_recursive(values, key, mid + 1, end);
}

bool binary_search(int* values, int key, int size) {
    return binary_search_recursive(values, key, 0, size - 1);
}