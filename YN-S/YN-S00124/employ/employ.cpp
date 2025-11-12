#include <bits/stdc++.h>
using namespace std;
const int N = 510;
const int mod = 998244353;
int n, m;
bool s[N];
int c[N];
int ans1;
int ans2;
int ans3;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n;
	cin >> m;
	int p = m;

	for (int i = 1; i <= n; i++) {

		cin >> s[i];
	}

	for (int i = 1; i <= n; i++) {

		cin >> c[i];
	}

	sort(c + 1, c + n + 1);

	for (int i = 1; i <= n; i++) {

		ans1 *= i;
		ans1 = ans1 % mod;
	}

	for (int i = 1; i <= p; i++) {

		ans2 *= i;
		ans2 = ans2 % mod;
	}

//ans>=ans2
	for (int i = 1; i <= (n - p); i++) {

		ans3 *= i;
		ans3 = ans3 % mod;
	}

	int ans = (ans1 / (ans2 * ans3 % mod)) % mod;
	cout << ans << endl;
	return 0;
}

