#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int T, top;
	char line[10001];
	char stack[10001];

	cin >> T;
	for (int t = 1; t <= T; t++) {
		top = -1;
		cin >> line;
		char *p = line;
		while (*p) {
			if (*p == '}' || *p == ']' || *p == ')') {
				if (top >= 0 && (*p == '}' && stack[top] == '{' || *p == ']' && stack[top] == '[' || *p == ')' && stack[top] == '(')) {
					top--;
				}
				else {
					break;
				}
			}
			else if (*p == '{' || *p == '[' || *p == '(') {
				stack[++top] = *p;
			}
			p++;
		}
		if (top >= 0 || *p) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}
	}
	return 0;
}
