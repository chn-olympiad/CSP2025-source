#include<bits/stdc++.h>
using namespace std;

int n, m, a[105], sum = 1, c, r;

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n * m; i++) {
        scanf("%d", &a[i]);
        if (a[i] > a[1])
                sum++;
    }
    c = (sum - 1) / n + 1;
    if (c % 2 == 1) {
        r = sum - (c - 1) * n;
    } else {
        r = n - sum + (c - 1) * n + 1;
    }
    printf("%d %d\n", c, r);
    return 0;
}
