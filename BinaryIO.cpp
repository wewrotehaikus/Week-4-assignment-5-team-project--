/* ---------------------------------------------------------------------------
** I attest that this following code represents my own work and is subject to
** the plagiarism policy found in the course syllabus.
**
**       Class: CSC 252 - Programming in C++
**  Assignment: Assignment 5
**        File: BinaryIO.cpp
** Description: Handles  opening streams, calculating file sizes, and reading/writing integer data to and from binary files for the BinaryReader class and writeBinary function.
**      Author: Karon Eley, Andre Gonzalez, Calvin Hart, Robert Wilson
**        Date: 25 April 2026
** -------------------------------------------------------------------------*/

#include "BinaryIO.h"
#include <fstream>

void writeBinary(std::string filename, int *values, int length)
{
    std::ofstream out(filename, std::ios::binary); // open file in binary mode for writing
    if (out.is_open())
    {
        out.write(reinterpret_cast<char *>(values), sizeof(int) * length);
        out.close();
    }
}

BinaryReader::BinaryReader(std::string filename) : data(nullptr), size(0)
{
    readValues(filename);
}

BinaryReader::~BinaryReader()
{
    delete[] data; // free up memory to prevent leaks
}

void BinaryReader::readValues(std::string filename)
{
    std::ifstream in(filename, std::ios::binary | std::ios::ate);
    if (in.is_open())
    {
        size = in.tellg() / sizeof(int); // find file size by jumping to end and dividing by size of int
        in.seekg(0, std::ios::beg);      // reset file pointer to the beginning before reading
        data = new int[size];            // allocate memory for hte integer array based on the file size
        in.read(reinterpret_cast<char *>(data), sizeof(int) * size);
        in.close();
    }
}

int *BinaryReader::getValues() { return data; }
int BinaryReader::getSize() { return size; }