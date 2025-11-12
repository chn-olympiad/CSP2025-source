#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 510;
int n, m, a[N], ans = 1;
string s;
bool test[N];

int jc(int x) {
	if (x < 2)
		return 1;
	int sum = 1;
	for (int i = 2; i <= x; i++) {
		sum *= i;
	}
	return sum;
}

int C(int n, int m) {
	if (n == 1)
		return m;
	if (n == m)
		return 1;
	int a = jc(m);
	int b = jc(n);
	int c = jc(m - n);
	return a / (b * c);
}

int cnt(int x) {
	int s = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] <= x)
			s++;
	}
	return s;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int cn = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i - 1] == '0') {
			test[i] = 0;
			cn++;
		} else
			test[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (test[i] == 1) {
			ans *= C(cnt(i), n);
		}
		n -= cnt(i);
		if (n == 0)
			break;
	}
	cout << (ans - cn) % mod;
	return 0;
}