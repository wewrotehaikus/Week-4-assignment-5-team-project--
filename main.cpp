/* ---------------------------------------------------------------------------
** I attest that this following code represents my own work and is subject to
** the plagiarism policy found in the course syllabus.
**
**       Class: CSC 252 - Programming in C++
**  Assignment: Assignment 5
**        File: main.cpp
** Description: The entry point of the program. It generates random test data, writes it to a binary file, reads it back, and runs various analyses on the data using different Analyzer classes.
**      Author: Karon Eley, Andre Gonzalez, Calvin Hart, Robert Wilson
**        Date: 25 April 2026
** -------------------------------------------------------------------------*/

#include <iostream>
#include <ctime>
#include "BinaryIO.h"
#include "Analyzers.h"

int main()
{
    srand(time(0));
    std::string filename = "data.bin";

    // Create some test data
    int data[500];
    for (int i = 0; i < 500; i++)
        data[i] = rand() % 1000;      // generate 500 random integers between 0 and 999
    writeBinary(filename, data, 500); // saves generated data to a binary file

    // Read and Analyze
    BinaryReader reader(filename);
    SearchAnalyzer sAn(reader.getValues(), reader.getSize());
    StatisticsAnalyser tAn(reader.getValues(), reader.getSize());
    DuplicatesAnalyser dAn(reader.getValues(), reader.getSize());
    MissingAnalyser mAn(reader.getValues(), reader.getSize());

    // Output results of the 4 different analysis tests
    std::cout << sAn.analyze() << std::endl;
    std::cout << tAn.analyze() << std::endl;
    std::cout << dAn.analyze() << std::endl;
    std::cout << mAn.analyze() << std::endl;

    return 0;
}