#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int N = 25;
const int M = 1e6 + 10;
const int mod = 998244353;

int n,m;
int a[N],c[N];
int dp[M][N];

void add (int &x,int y){
	x += y;
	if (x >= mod) x -= mod;
}
void solve(){
	cin >> n >> m;
	for (int i = 1 ; i <= n ; i++){
		char x; cin >> x;
		a[i] = x - '0';
	}
	for (int i = 1 ; i <= n ; i++) cin >> c[i];
	if (n == m){
		bool cc = 1;
		for (int i = 1 ; i <= n ; i++)
			if (!a[i] || !c[i]) cc = 0;
		cout << cc << endl;
		return;
	}
	dp[0][0] = 1;
	for (int mask = 0 ; mask < (1 << n) ; mask++){
		int tt = 0;
		for (int i = 0 ; i < n ; i++)
			if ((mask >> i) & 1) tt++;
		for (int i = 0 ; i < n ; i++){
			if ((mask >> i) & 1) continue;
			for (int j = 0 ; j < n ; j++){
				if (!dp[mask][j]) continue;
				if (j < c[i + 1]) add(dp[mask ^ (1 << i)][j + (!a[tt + 1])],dp[mask][j]);
				else add(dp[mask ^ (1 << i)][j + 1],dp[mask][j]);
			}
		}
	}
	/*
	for (int mask = 0 ; mask < (1 << n) ; mask++)
		for (int i = 0 ; i <= n ; i++)
			cout << "mask = " << mask << ' ' << i << ' ' << dp[mask][i] << endl;
	*/
	int ans = 0;
	for (int i = n - m ; i >= 0 ; i--)
		add(ans,dp[(1 << n) - 1][i]);
	cout << ans << endl;
}
signed main(){
	//freopen("employ1.in","r",stdin);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T = 1; //cin >> T;
	while (T--) solve();
	return 0;
}
