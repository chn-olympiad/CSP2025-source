#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;
int n, a[N][3], s[N], c[N];
void Solve() {
    cin >> n;
    int sum = 0, b[3] = {0};
    for (int i = 1; i <= n; ++i) {
        int mx = -1, k = -1;
        c[i] = 0;
        for (int j = 0; j < 3; ++j) {
            cin >> a[i][j];
            if (a[i][j] > mx) c[i] = mx, mx = a[i][j], k = j;
            else if (a[i][j] > c[i]) c[i] = a[i][j];
        }
        sum += mx, ++b[k], s[i] = k;
    }
    int p = max({ b[0], b[1], b[2] });
    if (p <= n / 2) {
        cout << sum << '\n';
    } else {
        int k = 0;
        if (p == b[1]) k = 1;
        else if (p == b[2]) k = 2;
        vector<pair<int, int>> v;
        for (int i = 1; i <= n; ++i) {
            if (s[i] == k) v.push_back({ -a[i][k] + c[i], i });
        }
        sort(v.begin(), v.end(), greater<pair<int, int>>());
        int i = 0;
        while (b[k] > n / 2) {
            // assert(i < (int)v.size());
            --b[k], sum += v[i++].first;
        }
        cout << sum << '\n';
    }
}
int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) Solve();
    return 0;
}