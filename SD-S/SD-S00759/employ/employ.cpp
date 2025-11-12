#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m, a[505], ans = 1;
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int x = 1;
	for(int i = 1; i <= m; i++){
		ans *= n;
		n--;
	}
	for(int i = 1; i <= m; i++){
		ans /= i;
	}
	cout << ans % 998244353;
	return 0;
}
