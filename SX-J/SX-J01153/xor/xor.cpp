#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, a[500010], s[500010];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = a[i] xor s[i - 1];
	}
	if (m == 0) {
		ll l = 1, r = 1, t = 0;
		while (l <= r && l <= n && r <= n) {
			if ((s[r] xor s[l - 1]) > m)
				r++;
			else if ((s[r] xor s[l - 1]) < m)
				l++;
			else
				t++, r++;
		}
		cout << t;
	} else {
		ll t = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				if ((s[j] xor s[i - 1]) == m)
					t++;
			}
		}
		cout << t;
	}
	return 0;
}
