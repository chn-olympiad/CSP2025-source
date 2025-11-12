#include <bits/stdc++.h>
using namespace std;

const unsigned long long mod = 18446744073709551615;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    int n, q;
    cin >> n >> q;
    
    vector<pair<string, string> > a;
    for (int k = 0; k < n; ++k) {
        string x, y;
        cin >> x >> y;
        a.push_back(make_pair(x, y));
    }

    while (q--) {
        int res = 0;

        string x, y;
        cin >> x >> y;

        int last = x.size() - 1;
        while (x[last] == y[last]) last--;

        for (auto i : a) {
            unsigned long long px = x.find(i.first), py = y.find(i.second);
            if (px != mod && px == py) {
                if (last < px + i.first.size())
                    if (px + i.first.size() <= x.size())
                        res++;
            }
        }

        cout << res << '\n';
    }

    return 0;
}
