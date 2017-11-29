#include <iostream>
#include <string>
using namespace std;

string str;

string vflip(string::iterator &s) {
	if (s[0] == 'x') {
		string lt = vflip(++s);
		string rt = vflip(++s);
		string lb = vflip(++s);
		string rb = vflip(++s);
		return "x" + lb + rb + lt + rt;
	}
	else {
		return string(1, s[0]);
	}
}

int main() {
	int T, t;
	cin >> T;
	for (t = 1; t <= T; t++) {
		cin >> str;
		string::iterator begin = str.begin();
		cout << vflip(begin) << endl;
	}

	return 0;
}
