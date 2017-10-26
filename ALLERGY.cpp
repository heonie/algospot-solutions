#include <iostream>
#include <string.h>
using namespace std;
#define MAX_N 50	// # of friends
#define MAX_M 50	// # of foods
#define MIN(X, Y)	(((X) <= (Y)) ? (X) : (Y))

int T, t, N, M;
bool caneat[MAX_M][MAX_N];	// Whether Person <2nd Index> can eat the food #<1st index>
string name[MAX_N];
char tmp[256];
int eat[MAX_N];	// How many foods the person <i> can eat currently
bool cooked[MAX_M];	// whether the food is cooked or not
int minFood;

bool everyoneCanEat() {
	for (int i = 0; i < N; i++) {
		if (eat[i] <= 0) {
			return false;
		}
	}
	return true;
}

void decideCookTheFood(int food, int count) {
	if (food >= M) {
		if (everyoneCanEat()) {
			minFood = MIN(minFood, count);
		}
		return;
	}
	if (count >= minFood) {
		return;
	}
	// not cook this food
	decideCookTheFood(food + 1, count);

	// cook this food
	for (int p = 0; p < N; p++) {
		if (caneat[food][p]) {
			eat[p]++;
		}
	}
	decideCookTheFood(food + 1, count + 1);
	for (int p = 0; p < N; p++) {
		if (caneat[food][p]) {
			eat[p]--;
		}
	}
}

void findStarving(int count) {
	int starving = -1;
	if (count >= minFood) {
		return;
	}
	for (int p = 0; p < N; p++) {
		if (eat[p] <= 0) {
			starving = p;
			break;
		}
	}
	if (starving < 0) {
		// everyone can eat something
		minFood = MIN(minFood, count);
		return;
	}
	int food = -1;
	for (int f = 0; f < M; f++) {
		if (!cooked[f] && caneat[f][starving]) {
			cooked[f] = true;
			for (int p = 0; p < N; p++) {
				if (caneat[f][p]) {
					eat[p]++;
				}
			}
			findStarving(count + 1);
			for (int p = 0; p < N; p++) {
				if (caneat[f][p]) {
					eat[p]--;
				}
			}
			cooked[f] = false;
		}
	}
}

int solution0() {
	minFood = 987654321;
	memset(eat, 0, sizeof(int)*N);
	decideCookTheFood(0, 0);
	return minFood;
}
int solution1() {
	minFood = 987654321;
	memset(eat, 0, sizeof(int)*N);
	memset(cooked, false, sizeof(bool)*M);
	findStarving(0);
	return minFood;
}

bool checkCombinations(int remained) {
	if (remained == 0) {
		if (everyoneCanEat()) {
			return true;
		}
		else {
			return false;
		}
	}
	for (int f = 0; f < M; f++) {
		if (!cooked[f]) {
			cooked[f] = true;
			for (int p = 0; p < N; p++) {
				if (caneat[f][p]) {
					eat[p]++;
				}
			}
			if (checkCombinations(remained - 1)) {
				return true;
			}
			for (int p = 0; p < N; p++) {
				if (caneat[f][p]) {
					eat[p]--;
				}
			}
			cooked[f] = false;
		}
	}
	return false;
}

int solution2() {
	memset(eat, 0, sizeof(int)*N);
	memset(cooked, false, sizeof(bool)*M);
	for (int c = 1; c <= M; c++) {
		if (checkCombinations(c)) {
			return c;
		}
	}
	return M;
}

int main() {
	cin >> T;
	for (t = 1; t <= T; t++) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			name[i] = string(tmp);
		}
		int count;
		memset(caneat, false, sizeof(bool)*MAX_M*MAX_N);
		for (int f = 0; f < M; f++) {
			cin >> count;
			for (int i = 0; i < count; i++) {
				cin >> tmp;
				for (int p = 0; p < N; p++) {
					if (name[p] == string(tmp)) {
						caneat[f][p] = true;
					}
				}
			}
		}

		//cout << solution0() << endl;	// too slow solution which takes exponential time
		cout << solution1() << endl;
		//cout << solution2() << endl;  // timeout!
	}
	return 0;
}
