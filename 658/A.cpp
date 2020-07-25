#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, m;
        scanf("%d%d",&n, &m);
        vector<int> a, b;
        int input;
        for (int i = 0; i < n; i++) {
            scanf("%d", &input);
            a.push_back(input);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d", &input);
            b.push_back(input);
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int i = 0, j = 0;
        int answer = 0;
        while (i < n && j < m) {
            if (a[i] == b[j]) {
                answer = a[i];
                ++i;
                ++j;
                break;
            }
            else if (a[i] > b[j]) {
                ++j;
            }
            else {
                ++i;
            }
        }

        if (answer == 0) {
            printf("NO\n");
        }
        else {
            printf("YES\n1 %d\n", answer);
        }
    }
    return 0;
}