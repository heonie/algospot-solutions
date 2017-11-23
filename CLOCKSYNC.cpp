#include <iostream>
using namespace std;
#define NUM_SWITCHES 10
#define MAX_CONNECTED 5
#define NUM_CLOCKS 16
#define MIN(X, Y) (((X)<=(Y))?(X):(Y))

int clk[NUM_CLOCKS];
int sw[NUM_SWITCHES][MAX_CONNECTED] = {
	{ 0, 1, 2, -1, -1 },
	{ 3, 7, 9, 11, -1 },
	{ 4, 10, 14, 15, -1 },
	{ 0, 4, 5, 6, 7 },
	{ 6, 7, 8, 10, 12 },
	{ 0, 2, 14, 15, -1 },
	{ 3, 14, 15, -1, -1 },
	{ 4, 5, 7, 14, 15 },
	{ 1, 2, 3, 4, 5 },
	{ 3, 4, 5, 9, 13 }
};

void pushSwitch(int s, int num, int dir) {
	for (int i = 0; i < MAX_CONNECTED; i++) {
		if (sw[s][i] >= 0) {
			clk[sw[s][i]] = (clk[sw[s][i]] + (num*3*dir) + 12) % 12;
		}
	}
}

int minCount = 987654321;

void handleSwitch(int s, int count) {
	if (s > NUM_SWITCHES-1) {
		for (int i = 0; i < NUM_CLOCKS; i++) {
			if (clk[i] != 0) {
				return;
			}
		}
		minCount = MIN(minCount, count);
		return;
	}
	for (int c = 0; c < 4; c++) {
		if (c <= 0) {
			handleSwitch(s + 1, count + c);
		}
		else {
			pushSwitch(s, c, 1);
			handleSwitch(s + 1, count + c);
			pushSwitch(s, c, -1);
		}
	}
}

int solution() {
	minCount = 987654321;
	handleSwitch(0, 0);
	return minCount < 987654321 ? minCount : -1;
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		for (int i = 0; i < 16; i++) {
			cin >> clk[i];
			clk[i] = clk[i] % 12;
		}
		cout << solution() << endl;
	}
	return 0;
}
