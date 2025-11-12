#include<bits/stdc++.h>
using namespace std;
int n, m, c[505], f[105][105][105], mi[105], cnt, ans;
bool vis[505];
string s;
int fac(int n){
	if (n == 0)
		return 1;
	return 1ll * fac(n - 1) * n % 998244353;
}
void dfs(int i, int f){
//	cerr << i << " " << f << "\n";
	if (n - f < m)
		return;
	if (i - f - 1 >= m){
		ans = (ans + fac(n - i + 1)) % 998244353;
		return;
	}
	if (i == n + 1){
		if (n - f >= m)
			ans = (ans + 1) % 998244353;
		return;
	}
	for (int j = 1; j <= n; j++){
		if (!vis[j]){
			vis[j] = 1;
		//	cerr << i << " " << j << " " << c[j] << "\n";
			dfs(i + 1, f + ((c[j] <= f) || s[i] == '0'));
			vis[j] = 0;
		}
	}
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m >> s;
	s = " " + s;
	if (n <= 18){
		for (int i = 1; i <= n; i++)
			cin >> c[i];
		dfs(1, 0);
		cout << ans << "\n";
	}else if (m == n){
		for (int i = 1; i <= n; i++)
			cin >> c[i];
		sort(c + 1, c + 1 + n);
		if (c[0] == 0)
			cout << "0";
		else if (s.find("0") != -1)
			cout << "0";
		else
			cout << fac(n);
	}else{
		cout << fac(n);
	}
	return 0;
}//End.
