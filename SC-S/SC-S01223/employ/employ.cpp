#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 2e5 + 5;
int n, m, k;
signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, ans = 1;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		ans = ans * i % 998244353;
	}
	cout << ans << endl;
	return 0;
} 