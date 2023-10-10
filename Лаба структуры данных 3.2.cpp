#include <iostream>
#include <string>
#include <fstream>

static class Logic {
public:
	static void relog(std::string& logic);
	static void relog(std::string& logic, int elem);
};

#include "Logic.h"

void Logic::relog(std::string& logic) {
	int size = logic.size();
	for (int i = 0; i < size; ++i) {
		if (logic[i] == '*') {
			if (logic[i - 1] == '1' && logic[i + 1] == '1') {
				logic.replace(i - 1, 3, "1");
				size -= 2;
			}
			else {
				logic.replace(i - 1, 3, "0");
				size -= 2;
			}
		}
	}
	for (int i = 0; i < size; ++i) {
		if (logic[i] == '-') {
			if (logic[i - 1] == '1' && logic[i + 1] == '1' || logic[i - 1] == '0' && logic[i + 1] == '0') {
				logic.replace(i - 1, 3, "0");
				size -= 2;
			}
			else {
				logic.replace(i - 1, 3, "1");
				size -= 2;
			}
		}
		if (logic[i] == '+') {
			if (logic[i - 1] == '0' && logic[i + 1] == '0') {
				logic.replace(i - 1, 3, "0");
				size -= 2;
			}
			else {
				logic.replace(i - 1, 3, "1");
				size -= 2;
			}
		}
		if (logic[i] == '~' && logic[i + 1] == '0') {
			logic.replace(i, 2, "1");
			size--;
		}
		if (logic[i] == '~' && logic[i + 1] == '1') {
			logic.replace(i, 2, "0");
			size--;
		}
		if (logic[i] == '~' && logic[i + 1] == '~') {
			logic.replace(i, 2, "");
			size -= 2;
		}
	}


}

void Logic::relog(std::string& logic, int elem) {
	int index = elem + 1;
	while (logic[index] != ')') {
		index++;
	}
	index++;
	for (int i = elem; i < index; ++i) {
		if (logic[i] == '~' && logic[i + 1] == '0') {
			logic.replace(i, 2, "1");
			index--;
		}
		if (logic[i] == '~' && logic[i + 1] == '1') {
			logic.replace(i, 2, "0");
			index--;
		}
		if (logic[i] == '~' && logic[i + 1] == '~') {
			logic.replace(i, 2, "");
			index -= 2;
		}
	}
	for (int i = elem; i < index; ++i) {
		if (logic[i] == '*') {
			if (logic[i - 1] == '1' && logic[i + 1] == '1') {
				logic.replace(i - 1, 3, "1");
				index -= 2;
			}
			else {
				logic.replace(i - 1, 3, "0");
				index -= 2;
			}
		}
	}
	for (int i = elem; i < index; ++i) {
		if (logic[i] == '-') {
			if (logic[i - 1] == '1' && logic[i + 1] == '1' || logic[i - 1] == '0' && logic[i + 1] == '0') {
				logic.replace(i - 1, 3, "0");
				index -= 2;
			}
			else {
				logic.replace(i - 1, 3, "1");
				index -= 2;
			}
		}
		if (logic[i] == '+') {
			if (logic[i - 1] == '0' && logic[i + 1] == '0') {
				logic.replace(i - 1, 3, "0");
				index -= 2;
			}
			else {
				logic.replace(i - 1, 3, "1");
				index -= 2;
			}
		}
	}
	logic.replace(elem, 1, "");
	logic.replace(index - 2, 1, "");
}

#include "Logic.h"
#include <stack>

int main() {
	std::ifstream file("file.txt");
	std::string logic;
	std::stack<int> elem;
	if (file.is_open()) {
		file >> logic;
		file.close();
		std::cout << logic << std::endl;
		for (int i = 0; i < logic.size(); i++) {
			if (logic[i] == '(') {
				elem.push(i);
			}
		}
		while (!elem.empty()) {
			Logic::relog(logic, elem.top());
			elem.pop();
		}
		int size = logic.size();
		for (int i = 0; i < size; i++) {
			if (logic[i] == '~' && logic[i + 1] == '0') {
				logic.replace(i, 2, "1");
				size--;
			}
			if (logic[i] == '~' && logic[i + 1] == '1') {
				logic.replace(i, 2, "0");
				size--;
			}
		}
		Logic::relog(logic);
		std::cout << logic << std::endl;
	}
	else {
		std::cout << "Error" << std::endl;
	}
	if (logic[0] == logic[4]) {
		std::cout << "True" << std::endl;
	}
	else {
		std::cout << "False" << std::endl;
	}
}
