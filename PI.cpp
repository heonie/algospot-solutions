#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits>
#define ABS(X) (((X) < 0) ? (-(X)) : (X))
using namespace std;
char PI[10001];
int cache[10001];
int N;
#define MAX_VAL 987654321

int difficulty(int s, int l) {
	int diff[5], i;
	for (i = 1; i < l; i++) {
		diff[i] = PI[s+i] - PI[s + i - 1];
	}
	
	for (i = 1; i < l; i++) {
		if (diff[i] != 0) {
			break;
		}
	}
	if (i == l) {
		return 1;	// every diff is 0
	}

	for (i = 2; i < l; i++) {
		if (diff[i] != diff[i-1] || (diff[i] != -1 && diff[i] != 1)) {
			break;
		}
	}
	if (i == l) {
		return 2;	// every diff is 1 or -1
	}

	for (i = 2; i < l; i++) {
		if (diff[i] != -(diff[i - 1])) {
			break;
		}
	}
	if (i == l) {
		return 4;	// repeating two numbers
	}

	for (i = 2; i < l; i++) {
		if (diff[i] != diff[i - 1]) {
			break;
		}
	}
	if (i == l) {
		return 5;	// repeating two numbers
	}
	return 10;
}

int minDifficulty(int s) {
	int diff;
	int &rst = cache[s];
	if (rst > 0) {
		return rst;
	}
	rst = MAX_VAL;
	for (int c = 3; c <= 5; c++) {
		if (N - (s + c) == 0) {
			rst = min(rst, difficulty(s, c));
		}
		else if (N - (s+c) >= 3) {
			rst = min(rst, difficulty(s, c) + minDifficulty(s + c));
		}
	}
	return rst;
}


int main() {
	int T, t;
	cin >> T;
	for (t = 1; t <= T; t++) {
		cin >> PI;
		N = strlen(PI);
		memset(cache, 0x00, sizeof(int) * 10001);
		cout << minDifficulty(0) << endl;
	}
	return 0;
}
