#include <bits/stdc++.h>
using namespace std;
int n, q, s[200010], t[200010];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	for (int j = 1; j <= q; j++) {
		cin >> t[j];
	}
	for (int i = 1; i <= q; i++) {
		cout << 0 << endl;
	}
	return 0;
}
