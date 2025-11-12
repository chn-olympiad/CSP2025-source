#include <bits/stdc++.h>
using namespace std;
int getrand(int x, int y) {
    return x + rand() % (y - x + 1);
}
int main() {
    freopen("xor12.in", "w", stdout);
    srand(clock());
    int n = 5e5, k = getrand(n + 1, (1 << 20) - 1);
    printf("%d %d\n", n, k);
    for (int i = 1; i <= n; i++) printf("%d%c", getrand(0, (1 << 20) - 1), i == n ? '\n' : ' ');
    //freopen("xor8.in", "w", stdout);
    //int m = (1 << 20) - 1;
    //printf("%d %d\n", 500000, m);
    //int n = 5e5;
    //for (int i = 1; i <= n; i++) printf("%d%c", m, i == n ? '\n' : ' ');
    return 0;
}
