#include <bits/stdc++.h>
using namespace std;
unsigned long long n, m, c[505], ans = 1, book, k, mk, sum;
string s;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m >> s;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
		if (s[i] == '0')
			book = 1;
		else if (k == 0)
			mk = i;
		if (s[i] == '1')
			k = 1;
	}
	if (book == 0) {
		int nn = n;
		for (int i = 1; i <= nn; i++) {
			ans *= n;
			n--;
		}
		cout << ans;
		return 0;
	}
	return 0;
}
