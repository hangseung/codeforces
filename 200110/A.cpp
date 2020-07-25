#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
    int n;
    string s;
    int lc = 0, rc = 0;
    cin >> n >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s.at(i) == 'L') {
            ++lc;
        }
        else if (s.at(i) == 'R') {
            ++rc;
        }
    }
    cout << lc + rc + 1;
    return 0;
}