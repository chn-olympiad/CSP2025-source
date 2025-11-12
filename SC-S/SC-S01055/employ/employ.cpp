#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const ll mod = 998244353;

int n, c[505], m;
string s;
ll ans, cnt;

void solve1() {
    vector<int> per;
    for (int i = 1; i <= n; i ++)
        per.push_back(i);
    do {
        int cnt = 0, fal = 0;
        for (int i = 0; i < n; i ++) {
            if (s[i] == '0')
                fal ++;
            else if (fal >= c[per[i]])
                fal ++;
            else 
                cnt ++;
        }
        if (cnt >= m)
            ans = (ans + 1) % mod;
        // for (auto x : per)
        //     cout << x << " ";
        // cout << "\n";
    } while(next_permutation(per.begin(), per.end()));
    cout << ans;
    exit(0);
}

void solve2() {

}

bool check(string ss) {
    for (int i = 0; i < ss.size(); i ++)
        if (s[i] != '1')
            return 0;
    return 1;
}

signed main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i ++)
        cin >> c[i];
    if (n <= 10)
        solve1();
    if (check(s)) {
        for (int i = 1; i <= n; i ++) 
            if (c[i] == 0)
                cnt ++;
        cout << cnt << "\n";
        if (n - cnt >= m) {
            ans = 1;
            for (ll i = 1; i <= n; i ++)
                ans = ans * i % mod;
            cout << ans;
        }
        return 0; 
    }
    if (m == n) {
    	int flg = 0;
    	for (int i = 1; i <= n; i ++)
    		if (c[i] == 0)
    			flg = 1;
    	if (!check(s))
    		flg = 1;
    	if (flg) {
    		cout << 0;
    		return 0;
		}
	} 
    if (m == 1) 
        solve2();
    return 0;
}