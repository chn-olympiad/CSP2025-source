#include<bits/stdc++.h>
#define froepen freopen
#define freopon freopen
#define int long long
#define REP(i, a, b) for (int i = a; i <= b; i ++)
#define pii pair<int,int>
using namespace std;
const int N = 1e5 + 10, mod = 998244353;
int c[N], s[N], vis[N], pa[N];
vector<int> p;
int n, m, ans;
void calc() {
	int pac = 0, cnt = 0;
	REP(i, 1, n) {
		if (pac >= c[pa[i]] || s[i] == 0) pac ++;
		else cnt ++;
	}
	ans += (cnt >= m);
	ans = ans >= mod ? ans - mod : ans;
}
void dfs(int cnt) {
	if (cnt > n) {
		calc();
		return;
	}
	REP(i, 1, n) {
		if (vis[i]) continue;
		vis[i] = 1;
		pa[cnt] = i;
		dfs(cnt + 1);
		vis[i] = 0;
	}
}
signed main() {
	froepen("employ.in","r",stdin);
	freopon("employ.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	bool M_N = (n == m);
	REP(i, 1, n) {
		char chr; cin >> chr;
		s[i] = chr - '0';
	}
	REP(i, 1, n) cin >> c[i];
	
	//subpoint
	if (M_N) {
		REP(i, 1, n) if (s[i] == 0 || c[i] == 0) {
			cout << 0;
			exit(0);
		}
		int ans = 1;
		REP(i, 1, n) ans = ans * i % mod;
		cout << ans;
		exit(0);
	}
	
	//baoli
	dfs(1);
	cout << ans;
	return 0;
//	puts("forepen");
//	puts("AFOAFOAFO");
//	puts("never gonna give you up");
//  yuan_shen_qi_dong?!
}
/*
10 1
1011011010
1 2 3 4 5 6 7 8 9 10
*/

