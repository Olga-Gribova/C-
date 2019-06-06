#include<iostream>
#include<map>
#include<fstream>
#include<string>
#include<vector>
#include<set>

int IN = 1;
int OUT = 0;

std::vector<std::string> words_searching(std::string & file_name) {
	std::ifstream input;
	input.open(file_name);
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
	return words;
}

int main() {

	std::map<std::string, int> bufwords;
	int max = 1;
	std::string file_name = "in.txt";
	std::vector<std::string> words = words_searching(file_name);
	
	for (auto & item : words) {
		bufwords[item]++;
		if (bufwords[item] > max)
			max = bufwords[item];
	}

	std::ofstream output;
	output.open("out.txt");

	for (int i = max; i > 0; i--) {
		for (auto & item : bufwords) {
			if (item.second == i) {
				output << item.second << ": " << item.first << std::endl;
			}
		}
	}

	return 0;
}
