#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod = 998244353;
int n, m, c[505], s[505]; string st;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> st;
	for (int i = 1; i <= n; i++){
		cin >> c[i]; s[i] = st[i] - 48;
	}
	int cnt = 0; long long ans = 1;
	for (int i = 1; i <= n; i++){
		if (c[i] == 0) cnt++;
	}
	for (int i = n; i >= n - m + 1; i--){
		ans *= i; ans %= mod;
	}
	cout << ans;
	return 0;
}
