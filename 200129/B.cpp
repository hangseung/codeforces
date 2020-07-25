#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int T;
    cin >> T;
    while (T--) {
        int n, x;
        string s;
        cin >> n >> x;
        cin >> s;
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += (s.at(i) == '0') ? 1 : -1;
        }
        int ans = 0;
        if (total != 0) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if ((x - sum) % total == 0 && (x - sum) / total >= 0) {
                    ++ans;
                }
                sum += (s.at(i) == '0') ? 1 : -1;
            }
        }
        else {
            int sum = 0;
            for (int i = 0; i < n && ans != -1; i++) {
                if (sum == x) {
                    ans = -1;
                }
                sum += (s.at(i) == '0') ? 1 : -1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}