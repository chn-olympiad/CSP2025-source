#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[100010], b[100010], c[100010];
vector<int> sa, sb, sc;
int m[100010];
int ans;
int n;

bool cmp(int x, int y) {
    return m[x] < m[y];
}
void move(vector<int> s) {
    sort(s.begin(), s.end(), cmp);
    for (int i = 0; i < s.size() - n / 2; i++) ans -= m[s[i]];
    cout << ans << "\n";
}
signed main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        ans = 0;
        sa.clear(), sb.clear(), sc.clear();
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i] >> c[i];
            int mx = max({a[i], b[i], c[i]}), mm = a[i] + b[i] + c[i] - mx - min({a[i], b[i], c[i]});
            m[i] = mx - mm;
            if (a[i] >= b[i] && a[i] >= c[i]) sa.push_back(i), ans += a[i];
            else if (b[i] >= a[i] && b[i] >= c[i]) sb.push_back(i), ans += b[i];
            else sc.push_back(i), ans += c[i];
        }
        if (sa.size() > n / 2) move(sa);
        else if (sb.size() > n / 2) move(sb);
        else if (sc.size() > n / 2) move(sc);
        else cout << ans << "\n";
    }
    return 0;
}

