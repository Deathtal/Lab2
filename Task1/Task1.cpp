#include <iostream>
#include <sstream>

bool is_sorted(const int int_array[], int& array_size) {
	for (int i = 0; i < array_size; i++) {
		if (int_array[i] < int_array[i-1]) {
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

	while(true) {
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

int main() {
	int array_size;
	
	int* input_int_array;
	input_int_array = new int[256];

	take_input_to_array(input_int_array, array_size);


	std::cout << (is_sorted(input_int_array, array_size) ? "Array is sorted" : "Array is not sorted") << std::endl;
	delete[] input_int_array;
}