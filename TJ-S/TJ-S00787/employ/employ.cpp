#include<bits/stdc++.h>
using namespace std;

const int P = 998244353;

int n, m, c[505], ans = 1, sum;
char s[505];

int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d%d", &n, &m);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
        if (c[i] == 0)
            sum++;
    }
    if (n - sum < m) {
        printf("0");
        return 0;
    }
    for (int i = 1; i <= n; i++)
        ans = 1LL * ans * i % P;
    printf("%d\n", ans);

    return 0;
}
