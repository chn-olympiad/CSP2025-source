#include <bits/stdc++.h>
using namespace std;
long long n, m, x, ans;
string s;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> s;
	}
	for (int i = 1; i <= n; i++){
		cin >> x;
	}
	if (m == 1){
		cout << 1;
		return 0;
	}
	for (int i = n; i >= 2; i--){
		ans = ans % 998244353 * i % 998244353;
		ans = ans % 998244353;
	}
	cout << ans;
	return 0;
}
