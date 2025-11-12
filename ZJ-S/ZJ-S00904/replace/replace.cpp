#include <bits/stdc++.h>
using namespace std;
long long n, q;
vector<pair<string, string>> a;
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> q;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    for (int i = 1; i <= q; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        long long ans = 0;
        for (int j = 1; j <= n; j++)
        {
            if (s1.find(a[j].first) != string::npos && s1.find(a[j].first) == (s1.find_last_of(a[j].first) - (a[j].first.size() - 1)) &&
                s2.find(a[j].second) != string::npos && s2.find(a[j].second) == (s2.find_last_of(a[j].second) - (a[j].second.size() - 1)))
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}