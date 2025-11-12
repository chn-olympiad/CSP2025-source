#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
int a[5100];

bool cmp(int aa, int b) {
	return aa > b;
}
bool f = true;
long long ans = 0;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != '1') {
			f = false;
		}
	}
	if (f) {
		sort(a + 1, a + 1 + n, cmp);
		for (int i = 1; i <= n; i++) {
			if (ans >= m) {
				break;
			}
			if (a[i] != 0) {
				ans++;
			}

//			ans %= MOD;
		}
//		cout << ans << endl;
		long long res = 1;
		for (int i = 1; i <= ans; i++) {
			res *= i;
//			res %= MOD;
		}
		ans = res;
	} else {
//		sort(a + 1, a + 1 + n);
		long long res = 1;
		for (int i = 1; i <= n; i++) {
			res *= i;
			res %= MOD;
		}
	}
	cout << ans;
	return 0;
}