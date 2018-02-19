#include <iostream>
using namespace std;
#define MAX_N 1001

int main() {
	int T, t, N, K, remain, c;
	bool alive[MAX_N];
	cin >> T;
	for (t = 1; t <= T; t++) {
		cin >> N >> K;
		fill(&alive[0], &alive[MAX_N - 1], true);
		remain = N;
		c = 0;
		while (remain > 2) {
			alive[c] = false;
			remain -= 1;
			int count = 0;
			while (count < K) {
				c = (c + 1) % N;
				if (alive[c])
					count++;
			}
		}
		c = 0;
		for (int i = 0; i < N; i++) {
			if (alive[i]) {
				if (c > 0) {
					cout << " ";
				}
				c++;
				cout << (i + 1);
			}
		}
		cout << endl;
	}
	return 0;
}
