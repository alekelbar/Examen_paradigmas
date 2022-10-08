#pragma once

#include <iostream>
#include <vector>
/**
 * @brief Merge sort algorithm merge
 *
 * @param vect
 * @param start
 * @param middle
 * @param end
 */
void merge(std::vector<int> &vect, int start, int middle, int end);
/**
 * @brief Merge sort algorithm implementation
 *
 * @param vect
 * @param start
 * @param end
 */
void mergeSort(std::vector<int> &vect, int start, int end);
/**
 * @brief how many elements in the vector are odd numbers
 *
 * @param v
 * @return int
 */
int howManyOdd(std::vector<int> v);
/**
 * @brief if a number is odd or not
 *
 * @param x
 * @return true
 * @return false
 */
bool oddNumber(int x);
/**
 * @brief swap memory location
 *
 * @param x
 * @param y
 */
void Swap(int &x, int &y);
/**
 * @brief Order pairs numbers ascending to the right side of v, and odd numbers descending to the left side of v
 *
 * @param v
 * @return std::vector<int>
 */
std::vector<int> orderPairsAndOdd(std::vector<int> &v);
/**
 * @brief A simple bubble sort algorithm modification to float an specific number to right side
 *
 * @param v
 */
void bubbleSortModified(std::vector<int> &v);

/**
 * @brief testing function for equality comparison
 *
 * @tparam T
 * @param a
 * @param b
 * @return true
 * @return false
 */
template <typename T>
bool Equal(T a, T b)
{
  return a == b;
}