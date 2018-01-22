#include <iostream>
#include <cstring>
using namespace std;
#define MAX_N 1001
#define MAX_M 1001

double cache[MAX_N][MAX_M];

double probability(int n, int m) {
	if (m <= 0) {
		return n > 0 ? 0 : 1;
	}
	else if (n <= 0) {	// && m > 0
		return 1;
	}
	double &rst = cache[n][m];
	if (rst >= 0) {
		return rst;
	}
	return rst = probability(n - 2, m - 1) * 0.75 + probability(n - 1, m - 1) * 0.25;
}

int main() {
	int T, t, n, m;
	cin >> T;
	for (t = 1; t <= T; t++) {
		cin >> n >> m;
		memset(cache, -1, sizeof(double) * MAX_N * MAX_M);
		cout << fixed;
		cout.precision(8);
		cout << probability(n, m) << endl;
	}
	return 0;
}
