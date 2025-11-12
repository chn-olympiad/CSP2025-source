#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
long long n, q, ans, pos;
string s[N][5], a, b, ya, yb;
unsigned long long k = 18446744073709551615;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i][1] >> s[i][2];
	}
	for (int i = 1; i <= q; i++) {
		ans = 0;
		cin >> a >> b;
		ya = a;
		yb = b;
		for (int j = 1; j <= n; j++) {
			a = ya;
			b = yb;
			if (a.find(s[j][1]) != k) {
				pos = a.find(s[j][1]);
				a.erase(pos, s[j][1].size());
				a.insert(pos, s[j][2]);
				if (a == b) {
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
