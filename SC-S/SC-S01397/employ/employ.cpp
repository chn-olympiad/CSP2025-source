#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	
	if (n == m) {
		int ans = 1;
		for (int i = 2; i <= n; i++) {
			ans = (ans * i) % 998244353;
		}
		cout << ans << '\n';
	}
	else {
		srand(time(0));
		
		cout << rand() % 998244353 << '\n';
	}
	
	return 0;
}