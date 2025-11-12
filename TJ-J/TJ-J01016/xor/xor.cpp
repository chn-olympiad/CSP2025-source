#include <bits/stdc++.h>
using namespace std;

int a[500005], sum[500005];
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    int n, k, cnt = 0;
    cin >> n >> k;

    bool pian = 1, pian2 = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum[i] = sum[i - 1] ^ a[i];

        if (a[i] != 1) {
            pian = 0;
        }
        if (a[i] > 1) {
            pian2 = 0;
        }
    }

    if (pian && k == 0) {
        cout << n / 2 << endl;
        return 0;
    }
    if (pian2 && k <= 1) {
        for (int i = 1; i <= n; i++) {
            if (a[i] == 1) {
                cnt++;
            }
        }
        if (k == 1) {
            cout << cnt << endl;
        } else {
            cnt = 0;
            for (int i = 1; i < n; i++) {
                if (a[i] == 0) {
                    cnt++;
                    continue;
                }
                if (a[i] == a[i + 1]) {
                    cnt++;
                    i++;
                }
            }
            if (a[n] == 0) {
                cnt++;
            }
            cout << cnt << endl;
        }
    }
    return 0;
}

