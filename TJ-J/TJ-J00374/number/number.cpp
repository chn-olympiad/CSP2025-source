#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int a[1000010];
signed main () {
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	ios :: sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	string s;
	cin >> s;
	int cz = 1;
	for (int i = 0; i < s.size(); i++) {
		char c = s[i];
		if (c >= '0' && c <= '9') {
			a[cz] = c - '0';
			cz++;
		}
	}
	sort (a + 1, a + cz);
	reverse (a + 1, a + cz);
	for (int i = 1; i < cz; i++) {
		cout << a[i];
	}
	return 0;
}
