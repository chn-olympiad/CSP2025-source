#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long u64;
typedef long long i64;

u64 n, q;
struct ss {
    string a, b;
}s[200010];

bool operator<(const ss& a, const ss& b) {
    return a.a < b.a;
}

bool operator<(const ss& a, const string &b) {
    return a.a < b;
}

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (u64 i = 1; i <= n; i++)
        cin >> s[i].a >> s[i].b;
    for (u64 i = 1; i <= q; i++) {
        string t1, t2;
        cin >> t1 >> t2;
        if (t1.size() != t2.size()) {
            cout << "0\n";
            continue;
        }
        u64 l = 0, r = t1.size() - 1;
        while (l <= r && t1[l] == t2[l])
            l++;
        while (l <= r && t1[r] == t2[r])
            r--;
        u64 sl = r - l + 1;
        u64 ans = 0;
        for (u64 j = 1; j <= n; j++)
            if (s[j].a.size() >= sl)
                for (u64 k = 0; k <= l && k + s[j].a.size() <= t1.size(); k++)
                    if (t1.substr(k, s[j].a.size()) == s[j].a && t2.substr(k, s[j].b.size()) == s[j].b)
                        ans++;
        cout << ans << '\n';
    }
}
