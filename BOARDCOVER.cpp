#include <iostream>
using namespace std;

int T, t;
int H, W;
char map[21][21];
int blocks[4][3][2] = {
	{ {0, 0}, {1, 0}, {0, 1} },
	{ {0, 0}, {1, 0}, {1, 1} },
	{ {0, 0}, {0, 1}, {1, 1} },
	{ {0, 0}, {0, 1}, {-1, 1} }
};

bool test(int y, int x, int type, int delta) {
	bool ret = true;
	for (int i = 0; i < 3; i++) {
		int pX = x + blocks[type][i][0];
		int pY = y + blocks[type][i][1];

		if (pX < 0 || pX > W - 1 || pY < 0 || pY > H - 1) {
			ret = false;
		}
		else {
			if (map[pY][pX] != '.') {
				ret = false;
			}
			map[pY][pX] += delta;
		}
	}
	return ret;
}

int delta = 1;
int getCount(int y, int x) {
	int sY, sX;
	int count = 0;
	for (sY = y; sY < H; sY++) {
		for (sX = x; sX < W; sX++) {
			if (map[sY][sX] == '.') {
				break;
			}
		}
		if (sX != W) {
			break;
		}
	}
	if (sY == H && sX == W) {
		return 1;
	}
	for (int type = 0; type < 4; type++) {
		++delta;
		if (test(sY, sX, type, delta)) {
			count += getCount(y, x);
		}
		test(sY, sX, type, -delta);
		--delta;
	}
	return count;
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> T;
	for (t = 1; t <= T; t++) {
		cin >> H >> W;
		for (int y = 0; y < H; ++y) {
			cin >> map[y];
		}

		cout << getCount(0, 0) << endl;
	}

	return 0;
}
