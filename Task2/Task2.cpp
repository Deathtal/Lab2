#include <iostream>

template<size_t N>
bool is_palindrome(const char (&char_array)[N]) {
	for (int i = 0; i < strlen(char_array) / 2; i++) {
		if (char_array[i] != char_array[strlen(char_array) - i - 1]) {
			return 0;
		}
	}
	return 1;
}

int main() {
	char char_array[256];

	std::cin >> char_array;

	std::cout << is_palindrome(char_array) << std::endl;
}