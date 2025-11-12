#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int M = (1 << 20) + 10;
int n, k, pos[M], f[N], a[N];
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] ^= a[i - 1];
    }
    for (int i = 0; i < M; i++) pos[i] = -1;
    pos[0] = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1];
        if (pos[a[i] ^ k] != -1) {
            f[i] = max(f[i], f[pos[a[i] ^ k]] + 1);
        }
        pos[a[i]] = i;
    }
    cout << f[n] << '\n';
    return 0;
}
