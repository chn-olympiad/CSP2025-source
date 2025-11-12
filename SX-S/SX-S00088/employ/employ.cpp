#include <bits/stdc++.h>
using namespace std;
long long ans = 1;
int n, m;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		ans = ans * i % 998244353;
	}
	cout << ans << endl;
	return 0;
}