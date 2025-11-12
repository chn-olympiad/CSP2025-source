#include <bits/stdc++.h>

#define N 505

using namespace std;

typedef long long ll;

// 变量定义
ll n, m;
ll ans = 0;
ll c[N];
bool visited[N];
bool gone[N];
ll hards[N];

struct ce {
    ll ind;
    ll value;
    bool operator < (const ce other) const {
        return value < other.value;
    }
} ;

vector<ce> cs;

void dfs(ll now, ll faileds, ll tabs) { // now为天数
    // cout << tabs << ": " << "dfs(" << now << ", " << faileds << ")" << endl;

    if (faileds > n - m) return ;
    if (now == n + 1) {
        ans++;
        ans %= 998244353;
        return ;
    }

    tabs++;

    for (ll i=1; i <= n; i++) {
        if (gone[i] || visited[i]) continue;
        // cout << "Trying " << i << endl;
        if (!hards[now]) {
            gone[i] = 1;
            faileds++;
        }
        else {
            visited[i] = true;
            // cout << i << " Employed." << endl;
        }
        // 处理放弃的人
        vector<ll> gones;
        for (ll i=0; i < n; i++) {
            if (gone[cs[i].ind] || visited[cs[i].ind]) continue;
            if (cs[i].value <= faileds) {
                // cout << cs[i].ind << " Goned." << endl;
                faileds++;
                gone[cs[i].ind] = 1;
                gones.push_back(cs[i].ind);
            }
        }

        dfs(now + 1, faileds, tabs);
        visited[i] = false;

        for (auto i : gones) {
            gone[i] = 0;
            faileds--;
        }
        gones.clear();

        if (!hards[now]) {
            faileds--;
            gone[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("employ.in", "r", stdin);
    freopen("emplot.out", "w", stdout);

    cin >> n >> m;

    string modes_s;
    cin >> modes_s;
    for (ll i = 0; i < (ll)modes_s.length(); i++) {
        hards[i + 1] = modes_s[i] - '0';
    }

    for (ll i = 1; i <= n; i++) {
        cin >> c[i];
        cs.push_back({i, c[i]});
    }

    sort(cs.begin(), cs.end());

    dfs(1, 0, 1);

    cout << ans;

    return 0;
}
