// Brute Force
#include <iostream>
using namespace std;

int H, W;
char map[21][21];
#define NUM_BLOCKS 4
bool blocks[NUM_BLOCKS][2][3] = {
    {   { 0, 1, 1 },
        { 0, 0, 1 } },
    
    {   { 0, 1, 1 },
        { 0, 1, 0 } },
    
    {   { 0, 1, 0 },
        { 0, 1, 1 } },
    
    {   { 0, 1, 0 },
        { 1, 1, 0 } },
};

bool setBlock(int cy, int cx, int bi, int inc) {
    int bx, by;
    bool conflict = false;
    for(int y=0; y<2; y++) {
        for(int x=0; x<3; x++) {
            if(!blocks[bi][y][x]) continue;
            bx = (cx-1+x);
            by = (cy+y);
            if(bx < 0 || bx >= W || by < 0 || by >= H) {
                conflict = true;
                continue;
            }
            if(map[by][bx] != '.') {
                conflict = true;
            }
            map[by][bx] += inc;
        }
    }
    return conflict;
}

int getCount (int sy, int sx) {
    int count = 0;
    for(int y=sy; y<H; y++) {
        for(int x=(y==sy?sx:0); x<W; x++) {
            if(map[y][x] == '.') {
                for(int i=0; i<NUM_BLOCKS; i++) {
                    if(!setBlock(y, x, i, 1)) {
                        int nx = x+1;
                        int ny = y;
                        if(nx >= W) {
                            nx = 0;
                            ny += 1;
                        }
                        count += getCount(ny, nx);
                    }
                    setBlock(y, x, i, -1);
                }
                return count;
            }
        }
    }
    return 1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int T, t;
    cin >> T;
    for(t=1; t<=T; t++) {
        cin >> H >> W;
        for(int i=0; i<H; i++) {
            cin >> map[i];
        }
        cout << getCount(0, 0) << endl;
    }
    return 0;
}
 
