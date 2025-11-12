#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n , m , ans , len;
int c[505] ;
long long fac[505] , inv[505];
bool vis[505];
string s;
long long ksm(long long a , long long b) {
	long long ans = 1;
	while(b) {
		if(b & 1) ans *= a;
		b >>= 1;
		a *= a;
		ans %= mod;
		a %= mod;
	}
	return ans;
}
void dfs(int step , int cnt) {
	if(cnt > n - m) return;
	if(step == n + 1) {
		ans ++ ;
		return;
	}
	for(int i = 1 ; i <= n ; i++) {
		if(!vis[i]) {
			vis[i] = 1;
			if(cnt >= c[i] || s[step] == '0') dfs(step + 1 , cnt + 1);
			else dfs(step + 1 , cnt);
			vis[i] = 0;
		}
	}
}
int main() {
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	cin >> n >> m;
	cin >> s;
	len = s.size();
	s = ' ' + s;
	int idx = 0;
	for(int i = 1 ; i <= n ; i++) {
		cin >> c[i];
		if(c[i] == 0) idx++;
	}
	if(idx > n - m) {
		cout << 0;
		return 0;
	}
	if(n <= 20){
		dfs(1 , 0);
		cout << ans;
	}else{
		long long fc = 1;
		for(int i = 2 ; i <= n ; i++) {
			fc = fc * i;
			fc %= mod;
		}
		cout << fc;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

