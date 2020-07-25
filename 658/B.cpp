#include <stdio.h>
#include <vector>

using namespace std;

int main () {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<int> a;
        int input;
        for (int i = 0; i < n; i++) {
            scanf("%d", &input);
            a.push_back((input >= 2) ? 2 : 1);
        }
        bool sw = true;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] == 2) {
                break;
            }
            sw = !sw;
        }
        if (sw) {
            printf("First\n");
        }
        else {
            printf("Second\n");
        }
    }
}