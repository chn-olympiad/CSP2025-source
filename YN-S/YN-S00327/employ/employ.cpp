#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	long long n, m, s = 0, s1 = 1;
	cin >> n >> m;
	for (int i = n; i <= n; i++) {
		for (int j = n; j >= n - i + 1; j--)
			s1 = s1 * j % 998244353;
		s += s1;
		s = s % 998244353;
	}
	cout << s % 998244353;
	return 0;
}