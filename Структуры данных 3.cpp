#include <iostream>
#include <string>
#include <fstream>
#include <vector>

void relog(std::string& logic) {
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
			size-=2;
		}
	}

}

void relog(std::string& logic, int elem) {
	int index = elem + 1;
	while (logic[index] != ')') {
		index++;
	}
	index++;
	for (int i = elem; i < index; ++i) {
		if (logic[i] == '*') {
			if (logic[i - 1] == '1' && logic[i + 1] == '1') {
				logic.replace(i-1, 3, "1");
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
	logic.replace(elem ,1, "");
	logic.replace(index-2, 1, "");
}


int main() {
	std::ifstream file("file.txt");
	std::string logic;
	std::vector<int> elem;
	if (file.is_open()) {
		file >> logic;
		file.close();
		std::cout << logic << std::endl;
		for (int i = 0; i < logic.size(); i++) {
			if (logic[i] == '(') {
				elem.push_back(i);
			}
		}
		for (int i = elem.size()-1; i >= 0; i--) {
			relog(logic, elem[i]);
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
		relog(logic);
		std::cout << logic << std::endl;
	}
	else {
		std::cout << "Error" << std::endl;
	}

}
