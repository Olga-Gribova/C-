#include<iostream>
#include<map>
#include<fstream>
#include<string>
#include<vector>
#include<set>

using namespace std;

int IN = 1;
int OUT = 0;

vector<string> words_searching(string & file_name) {
	ifstream input;
	input.open(file_name);
	vector<string> words;
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

	map<string, int> bufwords;
	int max = 1;
	string file_name = "in.txt";
	vector<string> words = words_searching(file_name);
	
	for (auto & item : words) {
		bufwords[item]++;
		if (bufwords[item] > max)
			max = bufwords[item];
	}

	ofstream output;
	output.open("out.txt");

	for (int i = max; i > 0; i--) {
		for (auto & item : bufwords) {
			if (item.second == i) {
				output << item.second << ": " << item.first << endl;
			}
		}
	}

	return 0;
}
