// Dynamic Programming
#include <iostream>
#include <string.h>
using namespace std;

int T, t, N;
char map[5][5];
char str[10][11];
bool found[10];
bool notthisway[10][10][10];

bool find(int i, int si, int y, int x) {
    if(str[i][si] == '\0') {
        return true;
    }
    if(y < 0 || y >= 5 || x < 0 || x >= 5) {
        return false;
    }
    if(notthisway[si][y][x]) {
        return false;
    }
    if(str[i][si] != map[y][x]) {
        notthisway[si][y][x] = true;
        return false;
    }
    
    if(find(i, si+1, y-1, x-1)) return true;
    if(find(i, si+1, y-1, x)) return true;
    if(find(i, si+1, y-1, x+1)) return true;
    if(find(i, si+1, y, x-1)) return true;
    if(find(i, si+1, y, x+1)) return true;
    if(find(i, si+1, y+1, x-1)) return true;
    if(find(i, si+1, y+1, x)) return true;
    if(find(i, si+1, y+1, x+1)) return true;
    notthisway[si][y][x] = true;
    return false;
}

void solution() {
    bool found;
    for (int i=0; i<N; i++) {
        found = false;
        memset(notthisway, 0, sizeof(bool)*10*10*10);
        for(int y=0; y<5; y++) {
            for(int x=0; x<5; x++) {
                if(find(i, 0, y, x)) {
                    found = true;
                    break;
                }
            }
            if(found) break;
        }
        cout << str[i] << ' ' << (found ? "YES" : "NO") << endl;
    }
}

int main(int argc, const char * argv[]) {
    cin >> T;
    for(t = 1; t<=T; t++) {
        for(int i=0; i<5; i++) {
            cin >> map[i];
        }
        cin >> N;
        for(int i=0; i<N; i++) {
            cin >> str[i];
            found[i] = false;
        }
        solution();
    }
    
    return 0;
}
