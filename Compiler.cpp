#include <iostream>
#include <fstream>
#include <string>

const char COMMANDS[] = {
	'+',
	'-',
	'<',
	'>',
	'.',
	',',
	'[',
	']',
};

const int ARRAY_LENGTH = 30000;

void HandleCommand(char command, unsigned int main_array[ARRAY_LENGTH], int* index) {
	if (command == COMMANDS[0]) {																			// INCREMENT
		main_array[*index] = main_array[*index] + 1;
	}
	else if (command == COMMANDS[1]) {																		// DECREMENT
		if (main_array[*index] != 0) {
			main_array[*index] = main_array[*index] - 1;
		}
	}
	else if (command == COMMANDS[2]) {																		// MOVE LEFT
		if (index != 0) {
			*index = *index - 1;
		}
	}
	else if (command == COMMANDS[3]) {																		// MOVE RIGHT
		*index = *index + 1;
	}
	else if (command == COMMANDS[4]) {																		// PRINT
		char output = main_array[*index];
		std::cout << output;
	}
	else if (command == COMMANDS[5]) {																		// TAKE INPUT
		char input;
		std::cin >> input;
		input = int(input);
		main_array[*index] = input;
	}
	else if (command == COMMANDS[6]) {																		// START LOOP
		
	}
	else if (command == COMMANDS[7]) {																		// END LOOP
		
	}
}

int main() {
	std::string line;
	std::ifstream main_file("main.bf");

	unsigned int main_array[ARRAY_LENGTH] = {};
	int index = 0;

	if (main_file.is_open()) {
		while (getline(main_file, line)) {
			for (unsigned int i = 0; i < line.length(); i++) {
				HandleCommand(line[i], main_array, &index);
			}
		}
	}
	else {
		std::cout << "No file detected. Did you ensure the file was titled 'Main.bf'?" << std::endl;
	}

	return 0;
}
