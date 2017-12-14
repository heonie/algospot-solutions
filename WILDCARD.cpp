#include <iostream>
#include <cstring>
using namespace std;

int N;
char wildcard[101];
char names[50][101];
int cache[101][101];

int compare(const void *a, const void *b) {
	return strcmp((const char *)a, (const char *)b);
}

bool match(const char *wc, const char *s) {
	while (*wc && *s && (*wc == '?' || *wc == *s)) {
		wc++;
		s++;
	}
	if (!*wc) {	// end of wildcard
		return *s == '\0';
	}
	else if (!*s) {	// end of string, but wildcard remained
		while (*wc) {
			if (*wc != '*') {
				return false;
			}
			wc++;
		}
		return true;
	}
	else if (*wc == '*') {
		return match(wc + 1, s) || match(wc, s + 1);
	}
	else {
		return false;
	}
}

int matchDP(const char *wc, int w, const char *name, int s) {
	int &rst = cache[w][s];
	if (rst != -1) {
		return rst;
	}
	while (wc[w] && name[s] && (wc[w] == '?' || wc[w] == name[s])) {
		w++;
		s++;
	}
	if (!wc[w]) {	// end of wildcard
		return rst = (name[s] == '\0') ? 1 : 0;
	}
	else if (!name[s]) {	// end of string, but wildcard remained
		while (wc[w]) {
			if (wc[w] != '*') {
				return (rst = 0);
			}
			w++;
		}
		return (rst = 1);
	}
	else if (wc[w] == '*') {
		return (rst = (matchDP(wc, w + 1, name, s) || matchDP(wc, w, name, s + 1)) ? 1 : 0);
	}
	else {
		return (rst = 0);
	}
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
			//if (match(&wildcard[0], &names[i][0])) {
			memset(cache, -1, sizeof(int) * 101 * 101);
			if (matchDP(wildcard, 0, names[i], 0)) {
				cout << names[i] << endl;
			}
		}
	}
	return 0;
}
