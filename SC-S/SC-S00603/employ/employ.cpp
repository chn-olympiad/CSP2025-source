#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 998244353;
int n, m, c[505];
string s;
int f[505];
ll ans;
void dfs (int k, int cnt){
	if (k >= n)
		return;
	if (k >= m){
		ans ++;
		ans %= mod;
	}
	for (int i = 1; i <= n; i ++)
		if (cnt >= c[i])
			f[i] = 1;
	for (int i = 1; i <= n; i ++){
		if (f[i] == 0){
			f[i] = 1;
			if (s[k] == '1')
				dfs (k + 1, cnt + 1);
			else
				dfs (k + 1, cnt);
			f[i] = 0;
		}
	}
	return;
}
int main (){
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	ios :: sync_with_stdio (false);
	cin.tie (0), cout.tie (0);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i ++)
		cin >> c[i];
	int g = 1;
	for (int i = 0; i < n; i ++){
		if (s[i] != '1'){
			g = 0;
			break;
		}
	}
	if (g){
		ll sum = 1;
		for (int i = 1; i <= n; i ++){
			sum *= i;
			sum %= mod;
		}
		cout << sum % mod;
		return 0;
	} 
	dfs (0, 0);
	cout << ans;
	return 0;
} 
/*
3 2
101
1 1 2
*/
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
