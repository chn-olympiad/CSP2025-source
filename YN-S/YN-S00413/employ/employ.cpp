#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int n, m, a[N], num;
long long ans = 1;
string s;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	num = n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 0) {
			num--;
		}
	}
	if (num < m) {
		cout << 0;
	} else {
		for (int i = 1; i <= num; i++) {
			ans *= i;
			ans %= 998244353;
		}
		cout << ans;
	}

	return 0;
}