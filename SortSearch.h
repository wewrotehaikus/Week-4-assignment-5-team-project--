/* ---------------------------------------------------------------------------
** I attest that this following code represents my own work and is subject to
** the plagiarism policy found in the course syllabus.
**
**       Class: CSC 252 - Programming in C++
**  Assignment: Assignment 5
**        File: SortSearch.h
** Description: A header file declaring the functions for performing selection sorting and recursive binary searching on an array of integers.
**      Author: Karon Eley, Andre Gonzalez, Calvin Hart, Robert Wilson
**        Date: 25 April 2026
** -------------------------------------------------------------------------*/

#pragma once

void selection_sort(int *values, int size);
bool binary_search(int *values, int key, int size);
bool binary_search_recursive(int *values, int key, int start, int end);