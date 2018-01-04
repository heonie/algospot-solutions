#include <iostream>
#include <cstring>
#include <climits>
#define MAX(X, Y) (((X)>=(Y)) ? (X) : (Y))
using namespace std;

int N, M;
int A[100], B[100];
int cache[101][101];

int jlis(int a, int b) {
	int &rst = cache[a+1][b+1];
	if (rst >= 0) {
		return rst;
	}
	int max = MAX(a < 0 ? INT_MIN : A[a], b < 0 ? INT_MIN : B[b]);
	rst = 0;
	for (int i = a + 1; i < N; i++) {
		if (A[i] > max) {
			rst = MAX(rst, (jlis(i, b)+1));
		}
	}
	for (int i = b + 1; i < M; i++) {
		if (B[i] > max) {
			rst = MAX(rst, (jlis(a, i)+1));
		}
	}
	return rst;
}

int main() {
	int t, T;
	cin >> T;
	for (t = 1; t <= T; t++) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		for (int i = 0; i < M; i++) {
			cin >> B[i];
		}
		memset(cache, -1, sizeof(int) * 101 * 101);
		cout << jlis(-1, -1) << endl;
	}
	return 0;
}
