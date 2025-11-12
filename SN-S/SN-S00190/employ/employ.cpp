#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("employ3.in", "r", stdin);
	freopen("employ3.out", "w", stdout);
	int n;
	cin >> n;
	long long ans = 1;
	for (int i = 1; i <= n; i++) {
		ans *= i;
	}
	cout << ans % 985244353;
	return 0;
} 
