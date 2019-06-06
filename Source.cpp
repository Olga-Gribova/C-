#include<iostream>
#include<map>
#include<conio.h>
#include<fstream>
#include<string>
#include<vector>
#include<set>


std::map<int, std::string> Build_Reversed_Map(std::map<std::string, int> & m) {
	std::map<int, std::string> reversed_m;
	for (auto & item : m) {
		reversed_m[item.second] = item.first;
	}
	return reversed_m;
}

int IN = 1;
int OUT = 0;


int main() {
	std::map<std::string, int> bufwords;
	//std::set<int> quantity;
	int max = 1;
	std::ifstream input;
	input.open("in.txt");

	//std::string word;

	std::vector<std::string> words;
	char buffer[256];
	char c;
	int i;
	int state;
	state = OUT;
	i = 0;
	while (input.get(c)) {

		if (c == EOF)
			break;

		if (c == ' ' || c == '\n' || c == '\t' || c == '\r' || c == '.' || c == ',' || c == '-' || c == '!' || c == '?' || c == ':' || c == ';' || c == '(' || c == ')' || c == '"') {
			if (state == IN) {
				// finish word
				state = OUT;
				buffer[i] = '\0';
				//value = atof(buffer);
				if (isupper(buffer[0]))
					buffer[0] = tolower(buffer[0]);
				words.push_back(buffer);
				i = 0;
			}
		}
		else if (state == OUT) {
			state = IN; // begin word
			buffer[i++] = c;
		}
		else {
			//inside word
			buffer[i++] = c;
		}
	}

	for (auto & item : words) {
		bufwords[item]++;
		if (bufwords[item] > max)
			max = bufwords[item];
	}

	std::ofstream output;
	output.open("out.txt");

	//std::map<int, std::string> reversed_words = Build_Reversed_Map(words);
	//std::map<int, std::string>::iterator cur;
	
	//for (auto & item : bufwords) {
	//	output << item.second << ": " << item.first << std::endl;
	//}

	for (int i = max; i > 0; i--) {
		for (auto & item : bufwords) {
			if (item.second == i) {
				output << item.second << ": " << item.first << std::endl;
			}
		}
	}

	return 0;
}