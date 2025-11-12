#include<bits/stdc++.h>

using namespace std;

// int find(int l, int r, int* a) {
//     int ret;
//     for (int i = l; i < r; i ++) {
//         for (int j = i; j < r; j ++) {
//             if
//         }
//     }
// }

int main() {
    freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    int a[n];
    int maxa { 0 };
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        if (a[i] > maxa) maxa = a[i];
    }
    do {
        int t = 0;
        for (int maxb = maxa;maxb;t ++) maxb >>= 1;
        maxa = 1 << t;
    } while(0);
    for(int i = 0; i < n - 1; i ++) {
        if (a[i] != a[i + 1])
            goto e;
    }
    if (k == 0) {
        cout << (int)n / 2;
        return 0;
    }
  e:
    int dp[maxa] { 0 };
    int t { 0 }, ans { 0 };
    for(int i = 0; i < n; i ++) {
        if (a[i] == k) {
            ans ++;
            dp[0] ++;
            t = 0;
            // cout << i << ": ";
            continue;
        }
        t ^= a[i];
        dp[t] ++;
        if (k && dp[t ^ k] || t == k) {
            dp[t ^ k] ? dp[t ^ k]--: dp[k]--;
            ans ++;
            t = 0;
            // cout << i << "; ";
        }
    }
    cout << ans;
    // cout << endl << (3^3);
}