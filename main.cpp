/* ---------------------------------------------------------------------------
** I attest that this following code represents my own work and is subject to
** the plagiarism policy found in the course syllabus.
**
**       Class: CSC 252 - Programming in C++
**  Assignment: Assignment 5
**        File: main.cpp
** Description: 
**      Author: Karon Eley, Andre Gonzalez, Calvin Hart, Robert Wilson
**        Date: 09 April 26
** -------------------------------------------------------------------------*/

#include <iostream>
#include <ctime>
#include "BinaryIO.h"
#include "Analyzers.h"

int main() {
    srand(time(0));
    std::string filename = "data.bin";

    // Create some test data
    int data[500];
    for(int i=0; i<500; i++) data[i] = rand() % 1000;
    writeBinary(filename, data, 500);

    // Read and Analyze
    BinaryReader reader(filename);
    SearchAnalyzer sAn(reader.getValues(), reader.getSize());
    StatisticsAnalyser tAn(reader.getValues(), reader.getSize());

    std::cout << sAn.analyze() << std::endl;
    std::cout << tAn.analyze() << std::endl;

    return 0;
}