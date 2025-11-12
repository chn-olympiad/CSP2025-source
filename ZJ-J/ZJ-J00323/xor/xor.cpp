#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    int a[n+5] = {0}, sum[n+5] = {0};
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] ^ a[i];
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if ((sum[j] ^ sum[i-1]) == k){
                cnt++;
                i = j + 1;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}