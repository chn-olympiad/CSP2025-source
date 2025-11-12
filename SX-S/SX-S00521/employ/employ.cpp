#include <bits/stdc++.h>
using namespace std;
const int N = 998244353;
int n, m;
string s;
int c[510];

int f() {
	long long ans1 = 1, ans2 = 1, ans3 = 1;
	for (int i = n; i > 1; i--) {
		ans1 *= i;
		ans1 %= N;
	}
	for (int i = m; i > 1; i--) {
		ans2 *= i;
		ans2 %= N;
	}
	for (int i = n - m; i > 1; i--) {
		ans3 *= i;
		ans3 %= N;
	}
	ans2 *= ans3;
	ans2 %= N;
	return ans1 / ans2;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	int len = s.size(), num1 = 0, num2 = 0;
	for (int i = 0; i <= len; i++)
		if (s[i] == '0')
			num1++;
	int minn = 510;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		minn = min(minn, c[i]);
		if (c[i] > num1)
			num2++;
	}
	if (m == 1)
		cout << num2 % N << endl;
	else if (m == n && minn > num1)
		cout << 0 << endl;
	else
		cout << f() % N << endl;
	return 0;
}
