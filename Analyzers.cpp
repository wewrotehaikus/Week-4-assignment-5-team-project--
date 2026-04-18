/* ---------------------------------------------------------------------------
** I attest that this following code represents my own work and is subject to
** the plagiarism policy found in the course syllabus.
**
**       Class: CSC 252 - Programming in C++
**  Assignment: Assignment 5
**        File: Analyzers.cpp
** Description: 
**      Author: Karon Eley, Andre Gonzalez, Calvin Hart, Robert Wilson
**        Date: 09 April 26
** -------------------------------------------------------------------------*/

#include "Analyzers.h"
#include "SortSearch.h"
#include <random>

Analyzer::Analyzer(int* values, int size) : size(size) {
    this->values = cloneValues(values, size);
}

Analyzer::~Analyzer() {delete[] values; }

int* Analyzer::cloneValues(int* source, int size) {
    int* copy = new int [size];
    for (int i = 0; i < size; ++i) copy[i] = source[i];
    return copy;
}

SearchAnalyzer::SearchAnalyzer(int* values, int size) : Analyzer(values, size) {
    selection_sort(this->values, this->size);
}

std::string SearchAnalyzer::analyze() {
    int found = 0;
    for (int i = 0; i < 100; ++i) {
        if (binary_search(values, rand() % 1000, size)) found++;
    }
    return "Search Results: " + std::to_string(found) + " values found.";
}

StatisticsAnalyser::StatisticsAnalyser(int* values, int size) : Analyzer(values, size) {
    selection_sort(this->values, this->size);
}

std::string StatisticsAnalyser::analyze() {
    if (size == 0) return "No values to analyze.";
    int min = values[0];
    int max = values [size - 1];
    double median = (size % 2 == 0) ? (values[size/2-1] + values[size/2])/2.0 : values[size/2];

// Simple Mode Logic
    int mode = values[0], maxCount = 0, currVal = values[0], currCount = 0;
    for(int i=0; i<size; i++) {
        if(values[i] == currVal) currCount++;
        else {
            if(currCount > maxCount) { maxCount = currCount; mode = currVal; }
            currVal = values[i]; currCount = 1;
        }
    }
    return "Min: " + std::to_string(min) + ", Max: " + std::to_string(max) + ", Median: " + std::to_string(median) + ", Mode: " + std::to_string(mode);
}