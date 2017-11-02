#include <iostream>
using namespace std;
#define MOD 1000000007
#define MAX_N 100

int cache[MAX_N + 1] = { 0, };

int getCount(int N) {
	if (N <= 1) return 1;
	int &rst = cache[N];
	if (cache[N] > 0) {
		return rst;
	}
	rst = (getCount(N - 1) + getCount(N - 2)) % MOD;
	return rst;
}

int main() {
	int T, t;
	cin >> T;
	for (t = 1; t <= T; t++) {
		int N;
		cin >> N;
		cout << getCount(N) << endl;
	}
	return 0;
}
