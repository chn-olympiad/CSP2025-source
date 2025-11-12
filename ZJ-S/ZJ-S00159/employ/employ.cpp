#include<bits/stdc++.h>
using namespace std;

int n, m, ans;
string s;
int c[505];
int vis[505];

void dfs(int id, int cnt){
	if(n - cnt < m) return;
	if(id == n){
		if(n - cnt >= m) ans = (ans + 1) % 998244353;
		return;
	}
	
	for(int i = 1; i <= n; i++){
		if(vis[i] == 1) continue;
		vis[i] = 1;
		if(c[i] <= cnt || s[id] == '0') dfs(id + 1, cnt + 1);
		else dfs(id + 1, cnt);
		vis[i] = 0;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m >> s;
	for(int i = 1; i <= n; i++) cin >> c[i];
	
	dfs(0, 0);
	cout << ans;
	
	return 0;
}