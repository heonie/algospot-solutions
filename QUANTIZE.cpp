#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, S;
int nums[101];
int accu[101];
int cache[100][10];

int sumErr(int begin, int end) {
	if (begin > end) {
		return 0;
	}
	int sum = accu[end] - (begin > 0 ? accu[begin-1] : 0);
	int avg = (int)(sum / (double)(end-begin+1) + 0.5);
	int sumErr = 0;
	for (int i = begin; i <= end; i++) {
		sumErr += (nums[i] - avg) * (nums[i] - avg);
	}
	return sumErr;
}

int minSumErr(int begin, int s) {
	int &rst = cache[begin][s];
	if (rst >= 0) {
		//cout << "(" << begin << "," << s << "): cached" << endl;
		return rst;
	}
	if (begin >= N) {
		return 0;
	}
	if (s <= 0) {
		if (begin < N) {
			//cout << "X" << endl;
			return 987654321;
		}
		else {
			//cout << endl;
			return 0;
		}
	}
	rst = 987654321;
	for (int end = begin; end < N; end++) {
		//cout << "[" << begin << ", " << (end) << "]";
		rst = min(rst, sumErr(begin, end) + minSumErr(end+1, s - 1));
	}
	return rst;
}

int compare(const void *a, const void *b) {
	return *((int *)a) - *((int *)b);
}

int main() {
	int T, t;
	cin >> T;
	for (t = 1; t <= T; t++) {
		cin >> N >> S;
		for (int i = 0; i < N; i++) {
			cin >> nums[i];
		}
		memset(cache, -1, sizeof(int) * 100 * 10);
		qsort(nums, N, sizeof(int), compare);
		for (int i = 0; i < N; i++) {
			accu[i] = i == 0 ? nums[i] : accu[i - 1] + nums[i];
		}
		cout << minSumErr(0, S) << endl;
	}
	return 0;
}
