#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10, M = 2e2 + 10, MOD =  998244353;
int n;
int a[N];
int ans = 0;
void dfs(int x, int sum, int MAX) {
//	cout << x << ' ' << sum << ' ' << MAX << ' ';
	if (sum > MAX * 2) {
		ans++;
		ans = ans % MOD;
//		cout << '*';
	}
	if (x > n) {
//		cout << '-';
		return;
	}
//	cout << '\n';
	for (int i = x + 1; i <= n; i++) {
		dfs(i, sum + a[i], max(MAX, a[i]));
	}
	
}
signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		
	}
	for (int i = 1; i <= n; i++) {
		dfs(i, a[i], a[i]);
		
	}
	cout << ans<< '\n';
	return 0;
}

