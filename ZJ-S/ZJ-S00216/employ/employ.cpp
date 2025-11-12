#include<bits/stdc++.h>

using ll = long long;
const int N = 510, mod = 998244353;
int n, m;
ll ans;
std::string s;
int c[N], p[N];
bool vis[N];

bool check(){
	int num = 0, cnt = 0;
	for(int i = 1; i <= n; ++i){
		if(num >= c[p[i]]){
			num++;
			continue;
		}
		if(s[i - 1] == '0') num++;
		if(s[i - 1] == '1') cnt++;
	}
	return cnt >= m;
}

void dfs(int k){
	if(k > n){
		if(check()) ans = (ans + 1) % mod;
		return;
	}
	for(int i = 1; i <= n; ++i){
		if(vis[i]) continue;
		vis[i] = true;
		p[k] = i;
		dfs(k + 1);
		vis[i] = false;
	}
	return;
}

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0), std::cout.tie(0);
	std::cin >> n >> m >> s;
	for(int i = 1; i <= n; ++i) std::cin >> c[i];
	dfs(1);
	std::cout << ans;
	return 0;
}

