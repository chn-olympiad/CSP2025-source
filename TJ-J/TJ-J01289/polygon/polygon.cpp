#include<bits/stdc++.h>
using namespace std;

const int P =  998244353;
long long f[5005][5005];
int n, a[5005];

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 3; i <= n; i++) {
        for (int j = 2; j < i; j++) {
            for (int k = 1; k < j; k++) {
                if (a[i] + a[j] > a[k])
                    f[i][3]++;
            }
        }
        f[i][3] %= P;
    }
    for (int i = 4; i <= n; i++) {
        for (int j = 3; j <= i; j++) {
            for (int k = j - 1; k <= i - 1; k++) {
                f[i][j] += f[k][j - 1];
                f[i][j] %= P;
            }
        }
    }
    long long ans = 0;
    for (int i = 3; i <= n; i++) {
        for (int j = 3; j <= i; j++) {
            ans += f[i][j];
            ans %= P;
        }
    }
    printf("%lld", ans);
    return 0;
}
