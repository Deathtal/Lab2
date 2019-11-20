#include "lab2lib.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <vector>

bool is_sorted(const int int_array[], int& array_size) {
	for (int i = 0; i < array_size; i++) {
		if (int_array[i] < int_array[i - 1]) {
			return 0;
		}
	}
	return 1;
}

bool is_valid_input(const std::string& str) {
	return str.find_first_not_of("0123456789 ") != std::string::npos;
}

void take_input_to_array(int*& int_array, int& array_size) {
	std::string input;
	std::string::size_type sz;
	int* temp_array;
	temp_array = new int[256];
	array_size = 0;

	do {
		std::cout << "Please enter an array of numbers, with each element seperated with a blankspace" << std::endl;
		std::getline(std::cin, input);
	} while (is_valid_input(input));

	while (true) {
		try {
			temp_array[array_size] = std::stoi(input, &sz);
			array_size++;
			input = input.substr(sz);
		}
		catch (std::invalid_argument & e) {
			break;
		}
		catch (std::out_of_range & e) {
			std::cout << "out of range" << std::endl;
			break;
		}
		catch (...) {
			std::cout << "there was an error in take_input_to_array" << std::endl;
			break;
		}
	}
	int_array = new int[array_size];
	for (unsigned int i = 0; i < array_size; ++i) {
		int_array[i] = temp_array[i];
	}
	delete[] temp_array;
}

void Task1() {
	int array_size;

	int* input_int_array;
	input_int_array = new int[256];

	take_input_to_array(input_int_array, array_size);


	std::cout << (is_sorted(input_int_array, array_size) ? "Array is sorted" : "Array is not sorted") << std::endl;
	delete[] input_int_array;
}


template<size_t N>
bool is_palindrome(const char(&char_array)[N]) {
	for (int i = 0; i < strlen(char_array) / 2; i++) {
		if (char_array[i] != char_array[strlen(char_array) - i - 1]) {
			return 0;
		}
	}
	return 1;
}

void Task2() {
	char char_array[256];

	std::cin >> char_array;

	std::cout << is_palindrome(char_array) << std::endl;
}


template<size_t N>
void array_rows_cols(const int(&twoD_array)[N][N]) {
	int array_size_x = N;
	int array_size_y = N;
	int x_sum = 0;
	int y_sum[N] = { 0 };
	int total_sum = 0;
	int x;
	int y;

	for (x = 0; x < array_size_x; x++) {
		if (twoD_array[x][0] == -1) {
			array_size_x = x;
			break;
		}
		for (y = 0; y < array_size_y; y++) {
			if (twoD_array[x][y] == -1) {
				array_size_y = y;
				break;
			}
			x_sum += twoD_array[x][y];
			std::cout << twoD_array[x][y] << "\t";
			y_sum[y] += twoD_array[x][y];
		}
		std::cout << "\033[1;31m" << x_sum << "\033[0m" << std::endl;
		total_sum += x_sum;
		x_sum = 0;
	}

	for (int i = 0; i < array_size_y; i++) {
		std::cout << "\033[1;31m" << y_sum[i] << "\033[0m\t";
		total_sum += y_sum[i];
	}

	std::cout << "\033[1;33m" << total_sum << "\033[0m" << std::endl;
}

void Task3() {
	int twoD_array[100][100];

	int x;
	int y;

	std::cout << "Enter the number of columns: ";
	std::cin >> x;

	std::cout << "Enter the number of rows: ";
	std::cin >> y;

	for (int i = 0; i < y + 1; i++) {
		for (int ii = 0; ii < x + 1; ii++) {
			if (ii >= x || i >= y) {
				twoD_array[i][ii] = -1;
			}
			else {
				twoD_array[i][ii] = rand() % 10;
			}
		}
	}

	array_rows_cols(twoD_array);
}


void swap_sort(int& a, int& b, int& c, const bool sort_asc) {
	if (sort_asc) {
		if (a > b&& a > c) {
			if (b < c) {
				int to_be_b = c;
				c = a;
				a = b;
				b = to_be_b;
			}
			else {
				int to_be_a = c;
				c = a;
				a = to_be_a;
			}
		}
		else if (a > b&& a < c) {
			if (b < c) {
				int to_be_b = a;
				a = b;
				b = to_be_b;
			}
			else {
				int to_be_b = a;
				a = b;
				b = to_be_b;
			}
		}
		else if (a < b && a < c) {
			if (b > c) {
				int to_be_b = c;
				c = b;
				b = to_be_b;
			}
		}
		else if (a < b && a > c) {
			int to_be_b = a;
			a = c;
			c = b;
			b = to_be_b;
		}
	}
	else {
		if (a > b&& a > c) {
			if (b < c) {
				int to_be_b = c;
				c = b;
				b = to_be_b;
			}
		}
		else if (a > b&& a < c) {
			if (b < c) {
				int to_be_b = a;
				a = c;
				c = b;
				b = to_be_b;
			}
			else {
				int to_be_b = a;
				a = b;
				b = to_be_b;
			}
		}
		else if (a < b && a < c) {
			if (b > c) {
				int to_be_b = c;
				c = a;
				a = b;
				b = to_be_b;
			}
			else {
				int to_be_c = a;
				a = c;
				c = to_be_c;
			}
		}
		else if (a < b && a > c) {
			int to_be_b = a;
			a = b;
			b = to_be_b;
		}
	}
}

void Task4() {
	int a;
	int b;
	int c;
	bool sort_asc = false;

	while (true) {
		std::cout << "Enter a value for a (enter 0 to quit): ";
		std::cin >> a;
		if (!a) {
			std::cout << "Exiting..." << std::endl;
			break;
		}
		std::cout << "Enter a value for b: ";
		std::cin >> b;
		std::cout << "Enter a value for c: ";
		std::cin >> c;
		std::cout << "Sort ascending/descending (1/0): ";
		std::cin >> sort_asc;

		swap_sort(a, b, c, sort_asc);

		std::cout << "Result: " << a << ", " << b << ", " << c << std::endl;
	}
}


template <size_t N>
void shrink_array(int(&int_array)[N]) {
	int temp_array[N / 2 + N % 2];
	int array_index = 0;
	for (int i = 1; i < N + N % 2; i += 2) {
		if (i < N) {
			temp_array[array_index] = int_array[i - 1] + int_array[i];
			array_index++;
		}
		else {
			temp_array[array_index] = int_array[i - 1];
		}
	}
	array_index = 0;
	for (int& i : int_array) {
		if (array_index < N / 2 + N % 2) {
			i = temp_array[array_index];
		}
		else {

			i = 0;
		}
		array_index++;
	}
}

void Task5() {
	int int_array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	std::cout << "input array:\t[ ";
	for (const int& i : int_array) {
		std::cout << i << "  ";
	}
	std::cout << "]" << std::endl;

	shrink_array(int_array);

	std::cout << "output array:\t[ ";
	for (const int& i : int_array) {
		std::cout << i << "  ";
	}
	std::cout << "]" << std::endl;
}

void InitialiseDatabase(std::vector<std::string>& vector) {
	std::string input;

	std::cout << "Everything saved on the databse will be removed. Are you sure?" << std::endl;
	std::cout << "Enter 'yes' to confirm: ";
	std::cin >> input;
	if (input == "yes") {
		vector.clear();
		std::cout << "Empty database has been initialised" << std::endl;
	}
}

void Insert(std::vector<std::string>& vector) {
	std::string input;

	std::cout << "Insert menu" << std::endl;

	while (true) {
		std::cout << "Enter a name to be inserted or enter 'Q' to return to the previus menu: " << std::endl;
		std::cout << "Insert: ";
		std::cin >> input;

		if (input == "Q") {
			return;
		}
		vector.push_back(input);
	}
}

void Search(std::vector<std::string>& vector) {
	if (vector.empty()) {
		std::cout << "The database is currently empty. Please return when something has been inserted into it." << std::endl;
		return;
	}

	std::string input;
	bool namefound = false;
	std::cout << "Search menu" << std::endl;

	while (true) {
		std::cout << "Enter something to search for names containing it or enter 'Q' to get the option to return to the previus menu: " << std::endl;
		std::cout << "Search: ";
		std::cin >> input;
		std::cout << std::endl;

		if (input == "Q") {
			std::cout << "Do you want to return to the previus menu or do you want to search for names containing 'Q'?" << std::endl;
			std::cout << "Enter 'return' to return to the previus menu or enter anything else to continue searching: ";
			std::cin >> input;
			if (input == "return") {
				return;
			}
			input = "Q";
			std::cout << std::endl;
		}

		for (std::string i : vector) {
			if (i.find(input) != std::string::npos) {
				namefound = true;
				std::cout << "Name found: " << i << std::endl;
			}
		}
		if (!namefound) {
			std::cout << "No name containing '" << input << "' was found" << std::endl;
		}
		std::cout << std::endl;
	}
}

void Delete(std::vector<std::string>& vector) {
	if (vector.empty()) {
		std::cout << "The database is currently empty. Please return when something has been inserted into it." << std::endl;
		return;
	}

	std::string input;

	std::cout << "Delete menu" << std::endl;

	while (true) {
		int names_found = 0;
		std::string searched_for_name;

		std::cout << "Please enter a name to delete or enter 'Q' to return to the previus menu" << std::endl;
		std::cout << "Delete: ";
		std::cin >> input;
		std::cout << std::endl;

		if (input == "Q") {
			return;
		}

		for (std::string name : vector) {
			if (name == input) {
				names_found++;
				searched_for_name = name;
			}
		}
		if (names_found == 0) {
			std::cout << "No such names was found" << std::endl;
			continue;
		}
		std::cout << names_found << " names found" << std::endl;
		if (names_found == 1) {
			std::cout << "Are you sure you want to delete this name from the database?" << std::endl;
			std::cout << "Enter 'yes' to delete: ";
			std::cin >> input;
			if (input == "yes") {
				for (std::vector<std::string>::iterator i = vector.begin(); i != vector.end(); ++i) {
					if (*i == searched_for_name) {
						vector.erase(i);
						break;
					}
				}
			}
		}
		else {
			int n;
			std::cout << "How many of the names do you want to delete?" << std::endl;
			std::cout << "Number to delete: ";
			std::cin >> n;

			if (n > names_found) {
				n = names_found;
			}
			for (; n > 0; n--) {
				for (std::vector<std::string>::iterator i = vector.begin(); i != vector.end(); ++i) {
					if (*i == searched_for_name) {
						vector.erase(i);
						break;
					}
				}
			}
		}
	}
}

void Print(std::vector<std::string>& vector) {
	if (vector.empty()) {
		std::cout << "The database is empty." << std::endl;
		return;
	}

	for (std::string i : vector) {
		std::cout << i << std::endl;
	}
}

struct {
	void(*function)(std::vector<std::string>&);
	const char* key;
} function_table[] = { {InitialiseDatabase, "initialise"}, {Insert, "insert"}, {Search, "search"}, {Delete, "delete"}, {Print , "print"}, {NULL, NULL} };


bool CallFunctionFromTable(const std::string& input_string, std::vector<std::string>& vector) {
	if (input_string == "quit") {
		return false;
	}
	for (int i = 0; function_table[i].function; i++) {
		if (input_string == function_table[i].key) {
			(*(function_table[i].function))(vector);
			return true;
		}
	}
	std::cout << "'" << input_string << "' is not a valid command, please try again" << std::endl;
	return true;
}


void Task6() {
	std::vector<std::string> names;
	std::string input;

	std::cout << "'Simple' database using vector" << std::endl;

	while (true) {
		std::cout << "\nCommands:\ninitialise\t: Initialises an empty database. Removing all content in the current database\ninsert\t\t: Brings you to a menu for inserting names to the database\nsearch\t\t: Brings you to a menu for searching for names in the database\ndelete\t\t: Brings you to a menu for deleting names in the database\nprint\t\t: Prints out all content of the database\nquit\t\t: Exit this program" << std::endl << std::endl << "Command: ";
		std::cin >> input;
		std::cout << std::endl;
		if (!CallFunctionFromTable(input, names)) {
			return;
		}
	}
}