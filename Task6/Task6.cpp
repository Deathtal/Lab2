#include <iostream>
#include <vector>


void InitialiseDatabase(std::vector<std::string> &vector) {
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
	}
}

void Delete(std::vector<std::string>& vector) {
	if (vector.empty()) {
		std::cout << "The database is currently empty. Please return when something has been inserted into it." << std::endl;
		return;
	}

	std::string input;
	bool namefound = false;
	std::cout << "Delete menu" << std::endl;

	while (true) {
		std::cout << "Please enter a name to delete or enter 'Q' to return to the previus menu" << std::endl;
		std::cout << "Delete: ";
		std::cin >> input;
		std::cout << std::endl;
	}
}

void Print(std::vector<std::string>& vector) {
	if (vector.empty()) {
		std::cout << "The database is empty." << std::endl;
		return;
	}
}

struct {
	void(*function)(std::vector<std::string>&);
	const char* key;
} function_table[] = { {InitialiseDatabase, "initialise"}, {Insert, "insert"}, {Search, "search"}, {Delete, "delete"}, {Print , "print"}, {NULL, NULL} };


bool CallFunctionFromTable(const std::string &input_string, std::vector<std::string>& vector) {
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

int main() {
	std::vector<std::string> names;
	std::string input;

	std::cout << "'Simple' database using vector" << std::endl;

	while (true) {
		std::cout << "\nCommands:\ninitialise\t: Initialises an empty database. Removing all content in the current database\ninsert\t\t: Brings you to a menu for inserting names to the database\nsearch\t\t: Brings you to a menu for searching for names in the database\ndelete\t\t: Brings you to a menu for deleting names in the database\nprint\t\t: Prints out all content of the database\nquit\t\t: Exit this program" << std::endl << std::endl << "Command: ";
		std::cin >> input;
		std::cout << std::endl;
		if (!CallFunctionFromTable(input, names)) {
			return 0;
		}
	}



	std::cin >> input;

}