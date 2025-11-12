#include <bits/stdc++.h>
using namespace std;
long long n, m = 1, x;
string s;
int c[505];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int i = 1; i <= n; i++) {
		m = m % 998244353 * (i % 998244353) % 998244353;
	}
	cout << m % 998244353 << endl;
	return 0;
}
