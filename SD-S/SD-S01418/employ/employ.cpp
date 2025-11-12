#include <bits/stdc++.h>
using namespace std;
const int N = 505, mod = 998244353;
int c[N], s[N], vis[N], ans, n, m, p[N];
void dfs(int k){
//	cout << k << endl ;
	if(k == n + 1){
	//	cout << k << endl ;
	//	for(int i = 1; i <= n; i ++) cout << p[i] << " " ; cout << endl;
		int sss = 0, ss = 0;
		for(int i = 1; i <= n; i ++){
			if(c[p[i]] > ss && s[i]) sss ++;
			else ss ++;
			if(sss >= m) {
				ans ++;
				ans %= mod;
				return ;
			}
		}
		return ;
	}
//	cout << 'r' ;
	for(int i = 1; i <= n; i ++){
		if(! vis[i]) {
			vis[i] = 1;
			p[k] = i;
			dfs(k + 1);
			vis[i] = 0;
		}
	}
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		char d;
		cin >> d;
		s[i] = d - '0';
	}
	for(int i = 1; i <= n; i ++) cin >> c[i];
	dfs(1);
	cout << ans ;
	return 0;
}
