#include <stdio.h>
#include <vector>

using namespace std;

int main () {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        
        vector<int> p;
        int input;
        for (int i = 0; i < n * 2; i++) {
            scanf("%d", &input);
            p.push_back(input);
        }

        vector<bool> chk(n * 2 + 1, false);
        int it = 2 * n;
        vector<int> lengths;
        int length = 0;
        for (int i = 2 * n - 1; i >= 0; i--) {
            ++length;
            chk[p[i]] = true;
            if (p[i] == it) {
                lengths.push_back(length);
                length = 0;
            }
            while (chk[it]) {
                --it;
            }
        }
        if (length > 0) {
            lengths.push_back(input);
        }

        vector<bool> d(n + 1, false);
        d[0] = true;
        for (int i = 0; i < lengths.size(); i++) {
            for (int j = n; j >= lengths[i]; j--) {
                if (d[j - lengths[i]]) {
                    d[j] = true;
                }
            }
        }

        if (d[n]) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
    return 0;
}