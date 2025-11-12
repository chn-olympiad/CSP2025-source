#include <bits/stdc++.h>
using namespace std;
long long ans = 0, n, m;
string s;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ3.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int z = 1; z <= n; z++) {
		int s_d;
		cin >> s_d;
		if (s_d == 0) {
			n--;
		}
	}
	for (int y = m ; y <= n; y++) {
		long long sum = 1;
		for (int z = y + 1; z <= n; z++) {

			sum *= z;
			sum %= 998244353;
		}
		//	sum %=
		ans += sum;
		ans %= 998244353;
	}

	cout << ans;
	return 0;
}
/*100 47
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
0 35 44 0 21 93 27 28 0 62 65 0 18 41 0 100 60 40 4 0 58 0 43 0 57 33 19 53 24 0 0 0 50 0 0 15 50 0 0 0 22 33 53 30 63 47 58 57 4 0 0 14 39 48 0 0 23 31 0 69 0 0 0 0 0 20 60 93 38 0 0 30 2 0 65 34 34 37 63 0 23 54 0 97 46 0 0 0 95 77 0 53 0 39 0 0 26 43 15 19
*/