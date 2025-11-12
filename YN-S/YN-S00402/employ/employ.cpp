#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
using ll = long long;
using ld = long double;
const int N = 1e6;
const ll mod = 998244353;
ll ans;
int n, m;
bool s[505];
int xin[505];
string strr;

ll func(int i) {
	if (i == 1)
		return 1;
	return func(i - 1) * i % mod;
}

int main () {
	IOS
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> strr;

	for (int i = 1; i <= n; i++) {

		s[i] = strr[i - 1] - '0';
	}

	for (int i = 1; i <= n; i++) {

		cin >> xin[i];
	}

	if (m == 1) {
		ans = func(n);

	} else if (m == n) {
		bool cann = true;

		for (int i = 1; i <= n; i++) {

			if (!s[i]) {
				cann = false;
				break;
			}

		}

		if (cann) {
			ans = 1;
		}

		else {
			ans = 0;
		}

	} else {
		ans = func(n);
	}

	ans %= mod;
	cout << ans  << endl;


	return 0;
}