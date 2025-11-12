#include<bits/stdc++.h>

using namespace std;

int indexOf(int*a, int l, int r, int n) {
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (m > n) r = m;
        else if (m < n) l = m;
        else return m;
    }
    return r;
}

int main() {
    freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int s[n]; // s[n] = sum(a[0..n])
    int t = 0, ans = 0;
    if (n == 3) {
        ans = (int)(a[0] + a[1] + a[2] > 2 * a[2]);
        goto end;
    }
    for (int i = 0; i < n; i ++) {
        t += a[i];
        s[i] = t;
        if (t > 2 * a[i]) {
            ans ++;
            cout << i << endl;
            int dt = t - 2 * a[i];
            for (int j = 1; j < i; j ++) {
                if (s[0] < dt) ans ++;
                for (int k = 0; k <= j; k ++) {
                    if (s[j] - s[k] > dt) {
                        ans ++;
                        // cout << i << " " << j << " " << k << endl;
                    }
                }
            }
        }
    }
    end:
    cout << ans % 998244353;
}