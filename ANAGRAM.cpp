#include <iostream>
#include <string>
#include <string.h>
using namespace std;
string serial, password;
int counter[256];

int main() {
	int T, t;
	cin >> T;
	for (t = 1; t <= T; t++) {
		cin >> serial >> password;
		if (serial == password) {
			cout << "No." << endl;
			continue;
		}
		memset(counter, 0x00, sizeof(int) * 256);
		for (string::iterator it = serial.begin(), end = serial.end(); it != end; it++) {
			counter[*it]++;
		}
		for (string::iterator it = password.begin(), end = password.end(); it != end; it++) {
			counter[*it]--;
		}
		int i = 0;
		for (i = 0; i < 256; i++) {
			if (counter[i] != 0) {
				break;
			}
		}
		if (i != 256) {
			cout << "No." << endl;
		}
		else {
			cout << "Yes" << endl;
		}
	}
	return 0;
}
