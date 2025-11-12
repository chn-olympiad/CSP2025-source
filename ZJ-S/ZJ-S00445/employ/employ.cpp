#include<bits/stdc++.h>
using namespace std;
#define N 501
#define int long long
const int MOD = 998244353;
bool b = 1;
string s;
int n,m,c[N],tot;
int chuai(int a[]){
	int los = 0,win = 0;
	for(int i = 1;i <= n;i++){
		if(los >= c[a[i]]) ++los;
		else if(s[i - 1] == '1') ++win;
		else ++los;
	}
	if(win >= m) return 1;
	return 0;
}
void dfs(int dep,bool u[],int a[]){
	if(dep == n + 1){
		tot = (tot + chuai(a)) % MOD;
		return;
	}
	for(a[dep] = 1;a[dep] <= n;a[dep]++){
		if(!u[a[dep]]){
			u[a[dep]] = 1;
			dfs(dep + 1,u,a);
			u[a[dep]] = 0;
		}
	}
	return;
}
signed main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	bool use[n + 1];
	int count = 0;
	for(int i = 1; i <= n; i++) {
		cin >> c[i];
		if(c[i] == 0) ++count;
		use[i] = 0;
	}
	for(auto ch : s) {
		if(ch != '1') {
			b = 0;
			break;
		}
	}
	int yag[n + 1];
	if(n - count < m){
		cout << 0;
		return 0;
	}
	if(b && count == 0) {
		int ans = 1;
		for(int i = n; i >= 1; i--) {
			ans = (ans * i) % MOD;
		}
		cout << ans;
		return 0;
	}
	dfs(1,use,yag);
	cout << tot;
	return 0;
}
