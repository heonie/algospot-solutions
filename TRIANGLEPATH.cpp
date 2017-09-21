#include <iostream>
using namespace std;

#define MAX(A, B)	(((A)>=(B)) ? (A) : (B))

int map[100][100];

int main() {
	int T, t, N;
	cin >> T;
	for (t = 1; t <= T; t++) {
		cin >> N;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x <= y; x++) {
				cin >> map[y][x];
			}
		}
		for (int y = N-2; y >= 0; y--) {
			for (int x = 0; x <= y; x++) {
				map[y][x] = map[y][x] + MAX(map[y + 1][x], map[y + 1][x + 1]);
			}
		}
		cout << map[0][0] << endl;
	}
	return 0;
}
