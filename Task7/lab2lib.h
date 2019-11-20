#pragma once

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <vector>

bool is_sorted(const int int_array[], int& array_size);

bool is_valid_input(const std::string& str);

void take_input_to_array(int*& int_array, int& array_size);

void Task1();


template<size_t N>
bool is_palindrome(const char(&char_array)[N]);

void Task2();


template<size_t N>
void array_rows_cols(const int(&twoD_array)[N][N]);

void Task3();


void swap_sort(int& a, int& b, int& c, const bool sort_asc);

void Task4();


template <size_t N>
void shrink_array(int(&int_array)[N]);

void Task5();


void InitialiseDatabase(std::vector<std::string>& vector);

void Insert(std::vector<std::string>& vector);

void Search(std::vector<std::string>& vector);

void Delete(std::vector<std::string>& vector);

void Print(std::vector<std::string>& vector);

bool CallFunctionFromTable(const std::string& input_string, std::vector<std::string>& vector);

void Task6();