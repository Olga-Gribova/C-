#include<iostream>
#include<map>
#include<fstream>
#include<string>
#include<vector>
#include<set>

using namespace std;

int IN = 1;
int OUT = 0;

void words_searching(string & file_name, map<string, int> & words, int & max) {
	max = 1;
	ifstream input;
	input.open(file_name);
	char buffer[256];
	char c;
	int i;
	int state;
	state = OUT;
	i = 0;
	while (input.get(c)) {
		if (c == ' ' || c == '\n' || c == '\t' || c == '\r' || c == '.' || c == ',' || c == '-' || c == '!' || c == '?' || c == ':' || c == ';' || c == '(' || c == ')' || c == '"' || c == EOF) {
			if (state == IN) {
				state = OUT;
				buffer[i] = '\0';
				if (isupper(buffer[0]))
					buffer[0] = tolower(buffer[0]);
				words[buffer]++;
				if (words[buffer] > max)
					max = words[buffer];
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
		if (c == EOF)
			break;
	} 
	if (state == IN) {
		buffer[i] = '\0';
		if (isupper(buffer[0]))
			buffer[0] = tolower(buffer[0]);
		words[buffer]++;
		if (words[buffer] > max)
			max = words[buffer];
	}
	input.close();
} 

int main() {

	map<string, int> words, stop_words;
	int max = 1;
	string file_name = "in.txt", stop = "stop.txt";
	words_searching(stop, stop_words, max);
	words_searching(file_name, words, max);
	
	ofstream output;
	output.open("out.txt");
	for (int i = max; i > 0; i--) {
		for (auto & item : words) {
			int counter = stop_words[item.first];
			if (item.second == i && counter < 1) {
				output << item.second << ": " << item.first << endl;
			}
		}
	}
	output.close();
	return 0;
}