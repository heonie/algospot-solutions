#include <iostream>
using namespace std;

#define MAX(A, B) (((A)>=(B))?(A):(B))
#define MIN(A, B) (((A)<=(B))?(A):(B))
int N;
int num[20001];

int getMaxArea(int l, int r) {
	if (l == r) {
		return num[l];
	}
	int mid = (l + r) / 2;
	int maxArea = 0;
	maxArea = MAX(maxArea, getMaxArea(l, mid));
	maxArea = MAX(maxArea, getMaxArea(mid+1, r));

	int lo = mid;
	int hi = mid + 1;
	int height = MIN(num[lo], num[hi]);
	maxArea = MAX(maxArea, height * 2);
	while (l < lo || hi < r) {
		if (l < lo && (r <= hi || num[lo - 1] >= num[hi + 1])) {
			lo--;
			height = MIN(num[lo], height);
		}
		else if (hi < r && (lo <= l || num[lo - 1] < num[hi + 1])) {
			hi++;
			height = MIN(num[hi], height);
		}
		maxArea = MAX(maxArea, height * (hi-lo+1));
	}
	return maxArea;
}

int main() {
	int T, t;
	cin >> T;
	for (t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> num[i];
		}
		cout << getMaxArea(0, N-1) << endl;
	}
	return 0;
}
