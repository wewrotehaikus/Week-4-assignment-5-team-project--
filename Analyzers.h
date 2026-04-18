/* ---------------------------------------------------------------------------
** I attest that this following code represents my own work and is subject to
** the plagiarism policy found in the course syllabus.
**
**       Class: CSC 252 - Programming in C++
**  Assignment: Assignment 5
**        File: Analyzers.h
** Description: Defines the base Analyzer class and its specialized subclasses for searching, statistics, duplicates, and missing value detection.
**      Author: Karon Eley, Andre Gonzalez, Calvin Hart, Robert Wilson
**        Date: 25 April 2026
** -------------------------------------------------------------------------*/

#pragma once
#include <string>
#include "SortSearch.h"

class Analyzer
{
protected:
    int *values;
    int size;

public:
    Analyzer(int *values, int size);
    virtual ~Analyzer();
    int *cloneValues(int *source, int size);
    virtual std::string analyze() = 0;
};

class SearchAnalyzer : public Analyzer
{
public:
    SearchAnalyzer(int *values, int size);
    std::string analyze() override;
};

class StatisticsAnalyser : public Analyzer
{
public:
    StatisticsAnalyser(int *values, int size);
    std::string analyze() override;
};

class DuplicatesAnalyser : public Analyzer
{
public:
    DuplicatesAnalyser(int *values, int size) : Analyzer(values, size)
    {
        selection_sort(this->values, this->size);
    }
    std::string analyze() override;
};

class MissingAnalyser : public Analyzer
{
public:
    MissingAnalyser(int *values, int size) : Analyzer(values, size)
    {
        selection_sort(this->values, this->size);
    }
    std::string analyze() override;
};