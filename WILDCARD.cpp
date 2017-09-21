#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int N;
char wildcard[101];
char names[50][101];

int compare(const void *a, const void *b) {
	return strcmp((const char *)a, (const char *)b);
}

bool match(char *w, char *name) {
	if (*w == '\0' && *name == '\0') {
		return true;
	}
	else if (*w == '\0') {
		return false;
	}

	if (*w == '?' || *w == *name) {
		return match(w + 1, name + 1);
	}
	else if (*w == '*') {
		int len = strlen(name);
		for(int i=0; i<=len; i++) {
			if (match(w + 1, name + i)) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	int T, t;
	cin >> T;
	for (t = 1; t <= T; t++) {
		cin >> wildcard;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> names[i];
		}
		qsort(names, N, sizeof(char) * 101, compare);
		for (int i = 0; i < N; i++) {
			if (match(&wildcard[0], &names[i][0])) {
				cout << names[i] << endl;
			}
		}
	}
	return 0;
}
