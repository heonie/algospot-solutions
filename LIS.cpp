#include <iostream>
#include <cstring>
using namespace std;
#define MAX(A, B) (((A) >= (B)) ? (A) : (B))

int N;
int num[500];
int lisCache[501];

int lis(int n) {
	int &result = lisCache[n+1];
	if (result >= 0) {
		return result;
	}
	int max = 0;
	for (int i = n+1; i < N; i++) {
		if (n < 0 || num[n] < num[i]) {
			max = MAX(max, lis(i));
		}
	}
	result = 1 + max;
	return result;
}

int main() {
	int T, t;
	cin >> T;
	for (t = 1; t <= T; t++) {
		cin >> N;
		memset(lisCache, (int)-1, sizeof(int) * (N+1));
		for (int i = 0; i < N; i++) {
			cin >> num[i];
		}
		cout << lis(-1)-1 << endl;
	}
	return 0;
}
