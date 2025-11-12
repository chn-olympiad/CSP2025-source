#include <bits/stdc++.h>

using namespace std;

const long long N = 505, mod = 998244353;
long long n, m;
string hard;
long long pat[N];
bool vis[N];
long long ans;
void dfs(long long now, long long go)
{
	if(now == n){
		if(n - go >= m){
			ans ++ ;
			ans %= mod;
		}
		return;
	}
	for(long long i = 1; i <= n; i ++ ){
		if(vis[i]) continue;
		vis[i] = true;
		if(hard[now] == '0' || go >= pat[i]){
			dfs(now + 1, go + 1);
		}
		else{
			dfs(now + 1, go);
		}
		vis[i] = false;
	}
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> hard;
	for(long long i = 1; i <= n; i ++ ) cin >> pat[i];
	dfs(0, 0);
	cout << ans;
	return 0;
}