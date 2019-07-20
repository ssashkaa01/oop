#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class File {

private:
	string source;
	string data;
	ifstream ifile;

public:
	File(string source) : source(source) {

		ifile.open(source);

		if (!ifile.is_open()) {
			cout << "File bad!" << endl;
		}
		else {
			string tmp;

			while (!ifile.eof()) {

				getline(ifile, tmp);
				if (tmp != "") {
					data += tmp + '\n';
				}

			}
		}
	}

	void ReserveData() {
		reverse(data.begin(), data.end());
	}

	int countWords() {

		int count = 0;

		for (int i = 0; i < data.length(); i++) {

			if ((data[i] == ' ' || data[i] == '\n') && (data[i + 1] != ' ' && data[i + 1] != '\n') ){
				count++;
			}
		}
		return count;
	}

	int countLines() {

		int count = 1;

		for (int i = 0; i < data.length(); i++) {

			if (data[i] == '\n') {
				count++;
			}
		}
		return count;
	}

	int countSentences() {

		int count = 0;

		for (int i = 0; i < data.length(); i++) {

			if (data[i] == '.' && data[i+1] != '.' && data[i - 1] != '.') {
				count++;
			}
		}
		return count;
	}

	void ShowData() const {
		cout << data;
	}

	void changeChar(char with, char to) {

		int count = 0;

		for (int i = 0; i < data.length(); i++) {

			if (data[i] == with) {
				data[i] = to;
				count++;
			}
		}
		cout << "Change: " << count << endl;
	}

	int searchLine(string str) {

		int count = 0;
		string tmp;

		for (int i = 0; i < data.length(); i++) {

			if (data[i] == '\n') {

				if (tmp == str) {
					count++;
				}

				tmp = "";
				
			}
			else {
				tmp += data[i];
			}
		}
		return count;
	}

	void changeLine(string with, string to) {

		int count = 0;
		int length = 0;
		string tmp;

		for (int i = 0; i < data.length(); i++) {

			if (data[i] == '\n') {

				if (tmp == with) {

					for (int j = 0; j < with.length(); j++) {


						if (j < to.length()) {
							data[i - length + j] = to[j];
						}
						else {
							data[i - length + j] = ' ';
						}

					}

					count++;
				}

				tmp = "";
				length = 0;

			}
			else {
				length++;
				tmp += data[i];
			}
		}
		cout << "Change: " << count << endl;
	}

	~File() {
		ofstream ofile(source, ios::trunc);
		ofile << data;
		ofile.close();
		ifile.close();
	}
};




int main() {

	File file("src.txt");
	//file.ReserveData();
	file.ShowData();

	cout << endl;

	//cout << file.countWords() << endl;
	//cout << file.countSentences() << endl;
	//cout << file.countLines() << endl;
	//file.changeChar('a', 'b');

	//cout << file.searchLine("bbbb") << endl;
	//file.changeLine("bbbb", "fff");

	system("pause");
	return 0;
}
