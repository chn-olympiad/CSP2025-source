#include <bits/stdc++.h>
using namespace std;

const long long mod = 998244353;
int a[5005];
int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    int n;
    cin >> n;

    bool pian = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] != 1) {
            pian = 0;
        }
    }

    if (n <= 3) {
        int maxn = max(max(a[1], a[2]), a[3]);
        int he = a[1] + a[2] + a[3];
        if (he > 2 * maxn) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
        return 0;
    }
    if (pian) {

    }
    return 0;
}

