#include "func.h"
#include <limits>
#include <string>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

string reverseWords(string stroka) {
	
	istringstream iss(stroka);
	string word, reverse;
	while (iss >> word) {
		reverse.insert(0, " ");
		reverse.insert(0, word);
	}
	reverse.resize(reverse.size() - 1);

	return reverse;
}


string join(string stroka1, string stroka2) {
	string joinStroka = stroka1 + " " + stroka2;

	return joinStroka;
}


string cut(string stroka, int length) {
	int i = 0;
	string temp = "";

	for (auto c : stroka) {
		if (length == i && stroka.length()>=i) {
			break;
		}
		temp += c;
		i++;
	}

	return temp;
}