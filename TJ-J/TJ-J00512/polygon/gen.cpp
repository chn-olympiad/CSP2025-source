#include <bits/stdc++.h>
using namespace std;
int getrand(int x, int y) {
    return x + rand() % (y - x + 1);
}
int main() {
    srand(clock());
    freopen("polygon12.in", "w", stdout);
    int n = getrand(4999, 5000);
    printf("%d\n", n);
    for (int i = 1; i <= n; i++) printf("%d%c", 1, i == n ? '\n' : ' ');
    return 0;
}
