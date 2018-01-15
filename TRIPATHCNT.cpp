#include <iostream>
#include <cstring>
using namespace std;
#define MAX_N 100

int N;
int map[MAX_N][MAX_N];
int cnt[MAX_N][MAX_N];

int main() {
	int T, t;
	cin >> T;
	for (t = 1; t <= T; t++) {
		cin >> N;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x <= y; x++) {
				cin >> map[y][x];
			}
		}
		memset(cnt, 0x00, MAX_N * MAX_N);
		for (int y = N-1; y >= 0; y--) {
			for (int x = 0; x <= y; x++) {
				if (y == N - 1) {
					cnt[y][x] = 1;
				}
				else {
					if (map[y + 1][x] > map[y + 1][x + 1]) {
						map[y][x] += map[y + 1][x];
						cnt[y][x] = cnt[y + 1][x];
					}
					else if (map[y + 1][x] < map[y + 1][x + 1]) {
						map[y][x] += map[y + 1][x + 1];
						cnt[y][x] = cnt[y + 1][x + 1];
					}
					else {//if (map[y + 1][x] == map[y + 1][x + 1]) {
						map[y][x] += map[y + 1][x];
						cnt[y][x] = cnt[y + 1][x] + cnt[y + 1][x + 1];
					}
				}
			}
		}
		cout << cnt[0][0] << endl;
	}
	return 0;
}
