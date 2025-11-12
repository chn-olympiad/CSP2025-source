//吴红燊 SN-S00118 西安湖滨中学
/*
luogu uid:743127
this is the way I still love something
bye,someone
CSP-S2025 RP++
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int T = 505+10,T2 = 20,inf = 1e18,mod = 998244353;
int n,m;
string s;
int c[T],v[T];
int dp[20][1<<18];
void add(int &x,int y) {
	x += y;
	x %= mod;
}
void sol1() {
	sort(c+1,c+n+1);
	dp[0][0] = 1;
	for(int i = 0;i <= (1<<n)-1;i++) {
		int po = 0;
		for(int j = 0;j < n;j++)
			if((i >> j) & 1) po++;
		for(int j = 0;j <= po;j++) {
			for(int k = 0,i2;k < n;k++) {
				if((i >> k) & 1) continue;
				i2 = i | (1<<k);
				if(po-j >= c[k+1] || v[po+1] == 0) {
					//wei
					add(dp[j][i2],dp[j][i]);
				}
				else add(dp[j+1][i2],dp[j][i]);
			}
//			cout << j << ' ' << i << " : " << dp[j][i] << '\n';
		}
	}
	int zans = 0;
	for(int i = m;i <= n;i++)
		add(zans,dp[i][(1<<n)-1]);
	cout << zans;
}
void sol2() {
	//all in
	for(int i = 1;i <= n;i++) {
		if(v[i] == 0 || c[i] == 0) {
			cout << 0;
			return ;
		}
	}
	int ans = 1;
	for(int i = 1;i <= n;i++)
		ans = ans * i % mod;
	cout << ans;
}
void solve() {
	cin >> n >> m;
	cin >> s,s = ' ' + s;
	for(int i = 1;i <= n;i++) v[i] = (s[i]-'0');
	for(int i = 1;i <= n;i++) cin >> c[i];
	if(n <= 18) {
		sol1();
		return ;
	}
	if(m == n) {
		sol2();
		return ;
	}
	cout << 0;
//	if(m == 1) {
//		sol2();
//		return ;
//	}
}
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
//	int t;cin >> t;while(t--)
	solve();
	return 0;
}
