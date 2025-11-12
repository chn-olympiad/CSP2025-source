#include <iostream>
using namespace std;
const int mod = 998244353;
long long n, m, a[505], nul, emt, ans = 1;
string s;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];

		if (a[i] == 0) {
			emt++;
		}
	}

	for (int i = 1; i <= n; i++) {

		if (s[i] == '0') {
			nul = 1;
			break;
		}
	}

	if (nul == 0) {
		for (int i = 1; i <= n - emt; i++) {

			ans = (ans * i) % mod;
		}

		cout << ans<<endl;
		return 0;
	}

	return 0;
}
