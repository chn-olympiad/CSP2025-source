#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 20;
const int P = 1 << 18;
const int MOD = 998244353;
int n, m, a[N], ans, jc[N], p[N];
char c[N];
bool vis[N];
void Dfs(int id, int sum){
	if(sum >= m){
		ans += jc[n - id + 1];
		ans %= MOD;
		return;
	}
	if(id == n + 1) return;
	for(int i = 1; i <= n; i++){
		if(vis[i]) continue;
		vis[i] = 1;
		p[id] = i;
		if(c[id] == '1' && a[i] > id - sum - 1) Dfs(id+1, sum+1);
		else Dfs(id+1, sum);
		vis[i] = 0;
	}
	return;
}
signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> c[i];
	jc[0] = 1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		jc[i] = (jc[i-1] * i) % MOD;
	}
	Dfs(1, 0);
	cout << ans << "\n";
	return 0;
}