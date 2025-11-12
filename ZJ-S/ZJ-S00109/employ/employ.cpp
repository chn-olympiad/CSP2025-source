#include <bits/stdc++.h>
using namespace std;
int MOD = 998244353;
int n, m, c[505];
int f[505][505];
string s;
void pre(int x){
	for (int i=1; i <= x; i++)  f[i][0] = f[i][i] = 1;
	for (int i=2; i <= x; i++){
		for (int j=1; j < i; j++)  f[i][j] = (f[i-1][j-1] + f[i-1][j]) % MOD;
	}
	return ;
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for (int i=1; i <= n; i++)  cin >> c[i];
	bool flag = 1;
	for (int i=0; i < n; i++){
		if (!s[i]){
			flag = 0;
			break;
		}
	}
	if (flag){
		int t = n;
		for (int i=1; i <= n; i++){
			if (c[i] == 0)  t--;
		}
		pre(t);
		cout << f[t][m] % MOD;
	}
	return 0;
}
//It's EXTREMELY dificult ! :( I won't like Z and H anymore :(
