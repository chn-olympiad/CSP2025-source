#include <bits/stdc++.h>

#define N 200005

using namespace std;

typedef long long ll;

// 变量定义
ll n, q;
ll ans = 0;
vector<ll> kmp[N];

string s[N][3];

void init_kmp(string x, ll now) {
    ll j = -1;
    for (ll i = 1; i < (ll)x.length() - 1; i++) {
        while (j >= 0 && x[j + 1] != x[i]) {
            j = kmp[now][j];
        }
        if (x[j + 1] == x[i]) j++;
        kmp[now][i] = j;
    }
}

void run_kmp(string x, string y, ll now, ll start_diff, ll end_diff) {
    ll j = -1;
    for (ll i = 0; i < (ll)x.length(); i++) {
        while (j >= 0 && s[now][1][j + 1] != x[i]) {
            j = kmp[now][j];
        }

        if (x[i] == s[now][1][j + 1]) j++;

        if (j == (ll)s[now][1].length() - 1) {
            // cout << s[now][1] << ": " << i - s[now][1].length() + 2 << endl;

            ll ind_from = i - s[now][1].length() + 1;
            if (ind_from <= start_diff && ind_from + (ll)s[now][1].length() - 1 >= end_diff) {
                // cout << "Trying " << s[now][1] << endl;
                // cout << "ind_from: " << ind_from << endl;
                ll flag = true;
                ll k2 = start_diff - ind_from;
                for (ll k = start_diff; k <= end_diff; k++) {
                    if (s[now][2][k2] != y[k]) {
                        flag = false;
                        break;
                    }
                    k2++;
                }
                if (flag) {
                    ans++;
                    // cout << "GO!" << endl;
                }
            }

            j = kmp[now][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    cin >> n >> q;

    for (ll i=1; i <= n; i++) {
        cin >> s[i][1] >> s[i][2];
        for (ll j=0; j <= (ll)s[i][1].length(); j++) {
            kmp[i].push_back(-1);
        }
        init_kmp(s[i][1], i);
    }

    while (q--) {
        ans = 0;
        ll start_diff = 0, end_diff;

        string x, y;
        cin >> x >> y;

        end_diff = x.length() - 1;
        if (x.length() != y.length()) {
            cout << 0 << endl;
            continue;
        }
        for (ll i=0; i < (ll)x.length(); i++) {
            if (x[i] != y[i]) {
                start_diff = i;
                break;
            }
        }
        for (ll i=(ll)x.length()-1; i >= 0; i--) {
            if (x[i] != y[i]) {
                end_diff = i;
                break;
            }
        }
        for (ll i=1; i <= n; i++) {
            if ((ll)s[i][1].length() < start_diff - end_diff + 1) continue;
            run_kmp(x, y, i, start_diff, end_diff);
        }
        cout << ans << endl;
    }

    return 0;
}
