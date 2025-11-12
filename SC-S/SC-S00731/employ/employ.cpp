#include <bits/stdc++.h>
#define int long long
using namespace std;

int t = 1;

const int N = 505, mod = 998244353;
int n, C[N];
char S[N];
int M, ans;

int vis[N];
void dfs(int u, int cnt, int hav, int awy) {
	if(n == cnt) {
		if(M <= hav) ans = (ans + 1) % mod;
//		cerr<<"\n";
//		cerr<<u<<" "<<cnt<<" "<<hav<<"::"<<ans<<"\n";
	}
	
	++ cnt;
	for(int i = 1; i <= n; i ++) {
		if(1 == vis[i]) continue;
		
//		cerr<<i<<" ";
		vis[i] = 1;
		if(C[i] <= awy || '0' == S[cnt]) dfs(i, cnt, hav, awy + 1);
		else dfs(i, cnt, hav + 1, awy);
		vis[i] = 0;
	}
}

void solve() {
	cin >> n >> M;
	for(int i = 1; i <= n; i ++) cin >> S[i];
	for(int i = 1; i <= n; i ++) cin >> C[i];
	
	for(int i = 1; i <= n; i ++) {
		
//		cerr<<i<<":::\n";
		vis[i] = 1;
		if(C[i] <= 0 || '0' == S[1]) dfs(i, 1, 0, 1); 
		else dfs(i, 1, 1, 0);
		vis[i] = 0;
//		cerr<<"\n";
	}
	cout << ans;
}

signed main() {
//	freopen("employ3.in", "r", stdin);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	while(t --) {
		solve();
	}
	return 0;
}
