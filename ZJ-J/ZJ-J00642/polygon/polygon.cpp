#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

const int N = 5e3 + 100, mod = 998244353;
int n, mx = -1, res = 0, a[N] = {}, vis[N] = {}, b[N] = {};

long long qpow(int x, int y){
	int res = 1;
	while(y){
		if(y & 1) res = res * x % mod;
		y /= 2;
		x = x * x % mod;
	}
	return res;
}

void dfs(int x, int s, int cnt, int m){
	
	if(x == s + 1 && 2 * m < cnt){
		res++;
		res %= mod;
		for(int i = 1; i <= s; i++) cout << b[i] << " \n"[i == s];
		return; 
	}
	
	for(int i = 1; i <= n; i++){
		if(vis[i] == 0 && i >= m || x == 1){
			vis[i] = 1;
			b[x] = a[i];
			dfs(x + 1, s, cnt + a[i], max(m, a[i]));
			vis[i] = 0;
		}
	}
	
}

int main(){

	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i], mx = max(mx, a[i]);
	
	if(mx <= 1){
		cout << (qpow(2, n - 1) - 1 - n - (n - 1) * n / 2) % mod << "\n";
	}else{
		for(int i = 3; i <= n; i++){
			dfs(1, i, 0, 0);
		}
		cout << res << "\n";
	}

	return 0;
}


