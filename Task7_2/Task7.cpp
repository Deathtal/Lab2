#include "lab2lib.h"
#include <iostream>

int main() {

	while (true) {
		int input;
		std::cout << "Menu:" << std::endl << std::endl;
		std::cout << "1: Task 1" << std::endl;
		std::cout << "2: Task 2" << std::endl;
		std::cout << "3: Task 3" << std::endl;
		std::cout << "4: Task 4" << std::endl;
		std::cout << "5: Task 5" << std::endl;
		std::cout << "6: Task 6" << std::endl;
		std::cout << "-1: Exit" << std::endl;
		std::cout << std::endl << "Option: ";
		std::cin >> input;

		if (std::cin.fail()) {
			std::cout << "Please enter a number" << std::endl << std::endl;
			std::cin.clear();
			std::cin.ignore();
			continue;
		}

		std::cin.clear();
		std::cin.ignore();

		switch (input) {
		case -1:
			return 0;
		case 1:
			Task1();
			break;
		case 2:
			Task2();
			break;
		case 3:
			Task3();
			break;
		case 4:
			Task4();
			break;
		case 5:
			Task5();
			break;
		case 6:
			Task6();
			break;
		default:
			std::cout << "'" << input << "' is not a valid option" << std::endl;
			break;
		}
		std::cout << std::endl << std::endl;
	}
}