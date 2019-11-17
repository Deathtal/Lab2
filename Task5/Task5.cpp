#include <iostream>

template <size_t N>
void shrink_array(int (&int_array)[N]) {
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
	for (int &i : int_array) {
		if (array_index < N / 2 + N % 2) {
			i = temp_array[array_index];
		}
		else {
			
			i = 0;
		}
		array_index++;
	}
}

int main() {
	int int_array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	std::cout << "input array:\t[ ";
	for (const int &i : int_array) {
		std::cout << i << "  ";
	}
	std::cout << "]" << std::endl;

	shrink_array(int_array);

	std::cout << "output array:\t[ ";
	for (const int &i : int_array) {
		std::cout << i << "  ";
	}
	std::cout << "]" << std::endl;
}