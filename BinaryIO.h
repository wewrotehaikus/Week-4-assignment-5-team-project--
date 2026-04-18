/* ---------------------------------------------------------------------------
** I attest that this following code represents my own work and is subject to
** the plagiarism policy found in the course syllabus.
**
**       Class: CSC 252 - Programming in C++
**  Assignment: Assignment 5
**        File: BinaryIO.h
** Description: Defines BinaryReader class for reading integers from a binary file and a function for writing integers to a binary file.
**      Author: Karon Eley, Andre Gonzalez, Calvin Hart, Robert Wilson
**        Date: 09 April 26
** -------------------------------------------------------------------------*/

#pragma once
#include <string>

void writeBinary(std::string filename, int *values, int length);

class BinaryReader
{
private:
    int *data;
    int size;

public:
    BinaryReader(std::string filename);
    ~BinaryReader();
    int *getValues();
    int getSize();
    void readValues(std::string filename);
};