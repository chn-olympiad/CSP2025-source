#include <iostream>
using namespace std;
int c[500];
long long cnt;
long long h = 998244353;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0')
			cnt += 1;
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	if (n == m && cnt != 0) {
		cout << 0;
		return 0;
	} else if (n == m && cnt == 0) {
		long long ans = 1;
		for (long long i = n; i >= 1; i -= 1) {
			ans *= i;
			ans %= h;
			cout << ans << endl;
		}
		cout << ans % h;
		return 0;
	}
	if (m == 1 && cnt != s.size()) {
		long long ans = 1;
		for (long long i = n; i >= 1; i -= 1) {
			ans *= i;
			ans %= h;
			cout << ans << endl;
		}
		cout << ans % h;
		return 0;
	} else if (m == 1 && cnt == s.size()) {
		cout << 0;
		return 0;
	}
	long long ans = 1;
	for (long long i = n; i >= 1; i -= 1) {
		ans *= i;
		ans %= h;
		cout << ans << endl;
	}
	cout << ans % h;
	return 0;
}
