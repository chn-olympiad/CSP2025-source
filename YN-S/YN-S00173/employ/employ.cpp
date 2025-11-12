#include <bits/stdc++.h>
using namespace std;
int n, m, sum, ans = 1;
string s;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;

	for (int i = 0; i < n; i++) {

		if (s[i] == 0) {
			sum++;
		}
	}

	if (sum > n - m) {
		cout << 0;
	} else {
		for (int i = 1; i < n; i++) {

			ans += i;
		}

		cout << ans;
	}

	return 0;
}