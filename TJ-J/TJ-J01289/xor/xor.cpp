#include<bits/stdc++.h>
using namespace std;

long long n, k, a[200005], f[200005];

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%lld%lld", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int l = 1; l <= n; l++) {
        long long sum = 0;
        for (int r = l; r <= n; r++) {
            sum ^= a[r];
            if (sum == k) {
                f[r] = max(f[r], f[l - 1] + 1);
                int p = r + 1;
                while (p <= n && f[p] < f[r]) {
                    f[p] = f[r];
                    p++;
                }
            }
        }
    }
    printf("%lld", f[n]);
    return 0;
}
