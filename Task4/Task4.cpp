#include <iostream>

void swap_sort(int &a, int& b, int& c, const bool sort_asc) {
	if (sort_asc) {
		if (a > b && a > c) {
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
		else if (a > b && a < c) {
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
		if (a > b && a > c) {
			if (b < c) {
				int to_be_b = c;
				c = b;
				b = to_be_b;
			}
		}
		else if (a > b && a < c) {
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

int main() {
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