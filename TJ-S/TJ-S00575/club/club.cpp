#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll t;
ll n, a[200010][3];

bool cmp(pair<pair<ll,ll>,pair<ll,ll>> x, pair<pair<ll,ll>,pair<ll,ll>>y) {
    return (x.first.first - x.second.first) < (y.first.first - y.second.first);
}

int main() {
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        vector<pair<pair<ll,ll>,pair<ll,ll>>> s(n + 10), d;
        ll la = 0, lb = 0, lc = 0, sum = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> a[i][j];
            }
            ll mx = max(a[i][0], max(a[i][1], a[i][2]));
            if (a[i][0] == mx) {
                s[i].first = {mx, 0};
                if (a[i][1] >= a[i][2]) s[i].second = {a[i][1], 1};
                else s[i].second = {a[i][2], 2};
                la++;
                sum += mx;
            }
            else if (a[i][1] == mx){
                s[i].first = {mx, 1};
                if (a[i][0] >= a[i][2]) s[i].second = {a[i][0], 0};
                else s[i].second = {a[i][2], 2};
                lb++;
                sum += mx;
            }
            else {
                s[i].first = {mx, 2};
                if (a[i][0] >= a[i][1]) s[i].second = {a[i][0], 0};
                else s[i].second = {a[i][1], 1};
                lc++;
                sum += mx;
            }
        }
        ll dif, no = 0;
        if (la > n / 2) {
            dif = 0;
            no = la - (n / 2);
        }
        else if (lb > n / 2) {
            dif = 1;
            no = lb - (n / 2);
        }
        else if (lc > n / 2) {
            dif = 2;
            no = lc - (n / 2);
        }
        else {
            cout << sum << "\n";
            continue;
        }
        for (int i = 1; i <= n; i++) {
            if (s[i].first.second == dif) {
                d.push_back(s[i]);
            }
        }
        sort(d.begin(), d.end(), cmp);
        for (int i = 0; i < no; i++) {
            sum -= (d[i].first.first - d[i].second.first);
        }
        cout << sum << "\n";
    }
    return 0;
}
