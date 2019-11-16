#include <iostream>
#include <cstdlib>

template<size_t N>
void array_rows_cols(const int (&twoD_array)[N][N]) {
	int array_size_x = N;
	int array_size_y = N;
	int x_sum = 0;
	int y_sum[N] = {0};
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

int main() {
	int twoD_array[20][20];

	int x;
	int y;

	std::cout << "Enter the number of columns: ";
	std::cin >> x;
	
	std::cout << "Enter the number of rows: ";
	std::cin >> y;

	for (int i = 0; i < 20; i++) {
		for (int ii = 0; ii < 20; ii++) {
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