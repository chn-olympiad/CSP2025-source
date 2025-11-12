#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 600;
int c[N], n, ans = 0, m, a[N];
bool vis[N];
string s;
void dfs(int t, int lu, int ju){
	if(t == n){
		int np = 0, x = 0;
		for(int i = 1; i <= n; i++){
			if(s[i-1] == '0'){
				np++;
				continue;
			}
			if(np >= c[a[i]]){
				np++;
				continue;
			}
			x++;
		}
		if(x >= m)
		ans++;
		ans %= mod;
		return ;
	}
	for(int i = n; i >= 1; i--){
		if(c[i] == -1) continue;
		if(ju >= c[i] && m-lu >= n-t) break;
		if(vis[i]) continue;
		vis[i] = 1;
		a[t+1] = i;
		if(s[t] == '1')
			dfs(t+1, lu+1, ju);
		else
			dfs(t+1, lu, ju+1);
		vis[i] = 0;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin>>n>>m;
	cin>>s;
	for(int i = 1;	i <= n; i++){
		cin>>c[i];
	}
	sort(c+1, c+1+n);
	if(n <= 18){
		dfs(0, 0, 0);
		cout<<ans;
		return 0;
	}
	ans = 1;
	
	for(int i = n; i >= 1; i--){
		ans *= i;
		ans %= mod;
	}
	cout<<ans;
	return 0;
}

