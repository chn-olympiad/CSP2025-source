#include <bits/stdc++.h>
using namespace std;
int n, m;
long long ans = 1;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	if (m == 1) {
		cout << n;
		return 0;
	}
	if (m == n) {
		cout << 1;
		return 0;
	}
	while (m--) {
		ans *= n;
		n--;
	}
	cout << ans;
	return 0;
}