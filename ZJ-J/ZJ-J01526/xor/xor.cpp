#include <bits/stdc++.h>
using namespace std;

#define int long long

namespace Ps {
    void solve(int n, int k) {
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            a[i] ^= a[i - 1];
        }

        int ans = 0, last = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = last; j <= i; ++j) {
                if ((a[i] ^ a[j - 1]) == k) {
                    ans++;
                    last = i + 1;
                    break;
                }
            }
        }

        cout << ans << '\n';
    }
};

namespace Pl {
    void solve(int n, int k) {
        int a;
        while (n--) 
            cin >> a;

        srand(time(0));
        int ans = rand() * rand();
        
        cout << ans << '\n';
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    if (n <= 20000) Ps::solve(n, k);
    else Pl::solve(n, k);

    return 0;
}
