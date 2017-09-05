#include <iostream>
#include <string.h>
using namespace std;

int T, t, N, M;
bool good[10][10];
bool paired[10];

int countPairs () {
    int count = 0;
    for(int i=0; i<N; i++) {
        if(!paired[i]) {
            for(int j=0; j<N; j++) {
                if(good[i][j] && !paired[j]) {
                    paired[i] = paired[j] = true;
                    count += countPairs();
                    paired[i] = paired[j] = false;
                }
            }
            return count;
        }
    }
    return 1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int a, b;
    cin >> T;
    for(t=1; t<=T; t++) {
        cin >> N >> M;
        memset(good, 0, sizeof(bool)*10*10);
        memset(paired, 0, sizeof(bool)*10);
        for(int i=0; i<M; i++) {
            cin >> a >> b;
            good[a][b] = good[b][a] = 1;
        }
        cout << countPairs() << endl;
    }
    
    return 0;
}
