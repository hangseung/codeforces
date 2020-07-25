#include <iostream>
#include <string>
#include <vector>

typedef unsigned long long int uint64_t;

#define max_bit ((uint64_t)1 << 63)

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string a, b;
        cin >> n >> a >> b;
        
        int l = 0, r = n - 1, p = n - 1;
        bool flipped = false;
        vector<int> logs;
        while (p >= 0) {
            char leftmost = a.at(l);
            char rightmost = a.at(r);
            if (flipped) {
                leftmost = '1' - a.at(r) + '0';
                rightmost = '1' - a.at(l) + '0';
            }
            if (rightmost == b.at(p)) {
                --p;
                if (flipped) {
                    ++l;
                }
                else {
                    --r;
                }
            }
            else if (leftmost != b.at(p)) {
                logs.push_back(p + 1);
                --p;
                flipped = !flipped;
                if (flipped) {
                    ++l;
                }
                else {
                    --r;
                }
            }
            else {
                string s;
                if (flipped) {
                    s += '1' - a.at(r) + '0';
                    a.replace(r, 1, s);
                }
                else {
                    s += '1' - a.at(l) + '0';
                    a.replace(l, 1, s);
                }
                logs.push_back(1);
            }
        }
        cout << logs.size() << " ";
        for (auto i : logs) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}