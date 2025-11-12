#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string s = "";
	cin >> s;
	int c[501];
	bool f = 1;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			f = 0;
			break;
		}
	}
	int sum = 0;
	for (int i = 0 ;i < m; i++) {
		cin >> c[i];
		if (c[i] == 0 ) {
			sum++;
		}
	}
	if (f) {
		long long sum1 = 1, sum2 = 1;
			for (int i = 1; i <= n - sum + 1; i++) {
				sum1 = (sum1 * i) % 998244353;
			}
			for (int j = 1; j <= sum; j++) {
				sum2 = (sum2 *j) % 998244353;
			}
			cout << (sum1 * sum2)% 998244353;
			return 0;
	} else if (m == 1){
		long long sum1 = 1, sum2 = 1;
		for (int i = 1; i <= n; i++) {
			sum1 = (sum1 * i) % 998244353;
		}
		cout << sum1;
		return 0;
	} else {
		cout << 0;
	}
	return 0;
}