#include<bits/stdc++.h>
using namespace std;
long long c[510], a[510], n, m, ans;
bool fl[510];                                         
string s;
void dfs(int i){
	if(i > n){
		int t = 0, r = 0;
		for(int j = 1; j <= n; j++){
			if(s[j - 1] == '0' || a[j] <= t) t++;
			else r++;
		}
		if(r >= m) ans++;
	}
	for(int j = 1; j <= n; j++){
		if(!fl[j]){
			fl[j] = 1;
			a[i] = c[j];
			dfs(i + 1);
			fl[j] = 0;
		}
	}
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for(int i = 1; i <= n; i++) cin >> c[i];
	dfs(1);
	cout << ans % 998244353;
	return 0;
}