#include <bits/stdc++.h>
using namespace std;
long long z = 998244353;

long long f(long long x) {
	for (long long i = x - 1; i >= 1; i--)
		x = (x * i) % z;
	return x % z;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	long long n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	bool p = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			p = 1;
			break;
		}
	}
	if (p == 0)
		cout << f(n) % z;
	else
		cout << 0;
	return 0;
}/*4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb*/