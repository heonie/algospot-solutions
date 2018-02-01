#include <iostream>
#include <cstring>
using namespace std;
#define MOD 10000000
#define MAX_N 101
int cache[MAX_N][MAX_N];

int poly(int top, int n) {
	if (n == 0) {
		return 1;
	}
	int &rst = cache[top][n];
	if (rst >= 0) {
		return rst;
	}
	rst = 0;
	for (int t = 1; t <= n; t++) {
		rst += (poly(t, n - t) * (top > 0 ? (top+t-1) : 1)) % MOD;
		rst = rst % MOD;
	}
	return rst;
}

int main() {
	int T, t, N;
	cin >> T;
	for (t = 1; t <= T; t++) {
		cin >> N;
		memset(cache, -1, sizeof(int) * MAX_N * MAX_N);
		cout << poly(0, N) << endl;
	}
	return 0;
}
