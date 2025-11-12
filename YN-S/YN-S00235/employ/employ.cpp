#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3 + 10;
int n, m, c[N], cnt;
string s;

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		if (c[i] == 1)
			cnt++;
	}
	if (cnt == n) {
		int i = 0, sum = 1;
		while (s[i] == '1') {
			i++;
		}
		if (i >= m) {
			for (int j = 2; j <= n; j++)
				sum *= j;
			cout << sum;
		} else
			cout << 0;
	} else {
		int sum = 1;
		for (int j = 2; j <= n; j++)
			sum *= j;
		cout << sum;
	}
	return 0;
}