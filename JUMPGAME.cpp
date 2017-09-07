#include <iostream>
#include <string.h>
using namespace std;

int N;
char map[101][101];
char cache[10000];

bool find(int y, int x) {
	if (x == N - 1 && y == N - 1) {
		return true;
	}
	char &found = cache[y * 100 + x];
	if (found > 0) {
		return found == 1;
	}
	int num = map[y][x] - '0';
	if (y + num < N && find(y+ num, x) || x + num < N && find(y, x+ num)) {
		found = 1;
		return true;
	}
	found = 2;
	return false;
}

bool solution() {
	return find(0, 0);
}

int main() {
	int T, t;
	cin >> T;
	for (t = 1; t <= T; t++) {
		cin >> N;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				cin >> map[y][x];
			}
		}
		memset(cache, 0x00, sizeof(char) * 100 * 100);
		cout << (solution() ? "YES" : "NO") << endl;
	}
	return 0;
}
