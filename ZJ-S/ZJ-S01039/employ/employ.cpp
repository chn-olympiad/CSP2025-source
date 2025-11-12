#include<bits/stdc++.h>
#define int long long
#define rep(i, r) for(int i = 1; i <= r; i++)
#define Rep(i, l, r) for(int i = l; i <= r; i++)
#define lep(i, r) for(int i = r; i; i--)
#define Lep(i, l, r) for(int i = r; i >= l; i--)
using namespace std;
const int N = 1 << 18, P = 998244353, M = 505;
//bool p1;
int n, m;
char s[M];
int f[N][20], c[M];
int count(int x) {
    int res = 0;
    while(x) x -= x & -x, res++;
    return res;
}
//bool p2;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
//    cerr << "Memory Used:" << (&p2 - &p1) / 1024.0 / 1024.0 << "Mb.";
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> s + 1;
    int cnt = 0;
    rep(i, n) cnt += s[i] == '1';
    if(m > cnt) return cout << 0, 0;
    rep(i, n) cin >> c[i];
    f[0][0] = 1;
    int rat = (1 << n) - 1;
    Rep(i, 0, rat - 1) {
    	int x = count(i);
		Rep(k, 0, x) rep(j, n) if(!((i >> j - 1) & 1)) {
    	    if(x - k >= c[j]) (f[i | (1 << j - 1)][k] += f[i][k]) %= P;
    	    else (f[i | (1 << j - 1)][k + (s[x + 1] - '0')] += f[i][k]) %= P;
    	}
	}
    int ans = 0;
    Rep(i, m, n) (ans += f[rat][i]) %= P;
    cout << ans;
    return 0;
}
//chzx_lfw AK IOI!!!!!