#include <bits/stdc++.h>
using namespace std;
int n, m;
long long ans, o = 1, tmp = 1;
string s;
int q;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = n - m; i <= n; i++) {
		o *= i;
		if (tmp > n - m) {
			o /= tmp;
			tmp++;
		}
		if (o > 998244353) {
			o %= 998244353;
		}
	}
	cin >> s;
	for (int i = 1; i <= n; i++)
		cin >> q;
	for (int i = 1; i <= m; i++) {
		o *= i;
		if (o > 998244353) {
			o %= 998244353;
		}
	}
	cout << o << endl;
	return 0;
}
