#include <iostream>
using namespace std;
#define MAX_N 50
#define MAX_D 101
int N, D, P;
char linked[MAX_N][MAX_N];
int deg[MAX_N];
int V, v[MAX_N];
double cache[MAX_N][MAX_D];

double prob(int cur, int d, int q) {
	if (d <= 0) {
		return cur == q ? 1.0 : 0.0;
	}
	double &rst = cache[cur][d];
	if (rst > -0.1) {
		return rst;
	}
	rst = 0.0;
	for (int i = 0; i < N; i++) {
		if (linked[cur][i] == '1') {
			rst += prob(i, d - 1, q) / deg[cur];
		}
	}
	return rst;
}

int main() {
	int t, T, V, v;
	cin >> T;
	for (t = 1; t <= T; t++) {
		cin >> N >> D >> P;
		fill(&deg[0], &deg[MAX_N], 0);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> linked[i][j];
				if (linked[i][j] == '1') {
					deg[i]++;
				}
			}
		}
		cin >> V;
		for (int i = 0; i < V; i++) {
			cin >> v;
			cout << fixed;
			cout.precision(8);
			fill(&cache[0][0], &cache[MAX_N - 1][MAX_D - 1], -1.0);
			cout << (i>0?" ":"") << prob(P, D, v);
		}
		cout << endl;
	}
	return 0;
}
