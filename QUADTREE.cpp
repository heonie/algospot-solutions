// Divide & Conquer
#include <iostream>
using namespace std;

string flipHori(string::iterator &head) {
    char ch = *head;
    head++; // pass the 'x', 'w' or 'b'
    if(ch == 'w' || ch == 'b') {
        return string(1, ch);    // return string filled with one single character
    }
    string ul = flipHori(head);
    string ur = flipHori(head);
    string ll = flipHori(head);
    string lr = flipHori(head);
    
    return string("x")+ll+lr+ul+ur;
}

int main(int argc, const char * argv[]) {
    int T, t;
    string comp;
    cin >> T;
    for(t=1; t<=T; t++) {
        cin >> comp;
        string::iterator begin = comp.begin();
        cout << flipHori(begin) << endl;
    }
    return 0;
}
