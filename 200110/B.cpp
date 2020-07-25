#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

long long int maximum (long long int a, long long int b) {
    return (a > b) ? a : b;
}

int main(void) {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        vector<int> a;
        long long int s = 0;
        for (int i = 0; i < n; i++) {
            int input;
            scanf("%d", &input);
            a.push_back(input);
            s += input;
        }
        long long int max = 0;
        long long int partialSum = 0;
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (flag && partialSum <= 0 && i != 0) {
                flag = false;
            }
            partialSum = maximum(0, partialSum) + a[i];
            if (!flag || i != n - 1) {
                max = maximum(partialSum, max);
            }
        }
        if (max < s) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
    return 0;
}