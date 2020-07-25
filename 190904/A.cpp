#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void) {
    int n, d, e;
    scanf("%d%d%d", &n, &d, &e);
    
    int ans = n;
    for (int i = 0; i <= n; i += d) {
        ans = min(ans, (n - i) % (e*5));
    }

    printf("%d", ans);
    return 0;
}