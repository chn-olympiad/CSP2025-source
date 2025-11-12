#include <bits/stdc++.h>
using namespace std;
int a[10005];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	long long n, m, sum = 0, ans = 1;
	string s;
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 0) {
			sum++;
		}
	}
	for (int i = 1; i <= sum; i++) {
		ans = (ans *i) % 998244353;
	}
	cout << ans;
	return 0;
}
