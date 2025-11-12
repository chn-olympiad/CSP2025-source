#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e2 + 10, mod = 998244353;
int read(){
	int x; scanf("%lld", &x); return x;
}
int n, m, len, res, ans;
string s;
int c[N], book[N], b[N];
void dfs(int t){
	if(t == n + 1){
		int res = 0;
		for(int i = 1; i <= n; i++){
			if(res >= c[b[i]]){
				res++;
				continue;
			} 
			if(s[i] == '0') res++;
			//cout << res << ' ';
		}
		//cout << endl;
		if(n - res >= m) ans = (ans + 1) % mod;
		return;
	}
	for(int i = 1; i <= n; i++){
		if(!book[i]){
			book[i] = 1;
			b[t] = i;
			dfs(t + 1);
			book[i] = 0;
		}
	}
}
signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = read(); m = read();
	cin >> s;
	len = s.size();
	s = '#' + s;
	for(int i = 1; i <= n; i++) c[i] = read();
	for(int i = 1; i <= len; i++){
		if(s[i] == '1') res++;
	}
	if(res == n){
		printf("%lld", n % mod);
		return 0;
	}
	dfs(1);
	printf("%lld", ans);
	return 0;
}
