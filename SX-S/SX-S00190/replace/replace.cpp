#include <bits/stdc++.h>
using namespace std;
string re[20005][3], a1, b1, x, z;
int n, q, ans;

void finds(string a, string b) {
	int l1 = a.size(), l2 = b.size();
	int f = 1;
	for (int i = 0; i < l1; i++) {
		if (f && a[i] == b[0]) {
			f = 0;
			for (int j = 0; j < l2; j++, i++) {
				if (a[i] != b[j]) {
					f = 1;
					i -= j;
					break;
				}
			}
			for (int j = i; j < l1; j++) {
				z = z + a[i];
			}
		}
		if (f) {
			x = x + a[i] ;
		}
	}
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> re[i][1] >> re[i][2];
	}
	while (q--) {
		cin >> a1 >> b1;
		ans = 0;
		for (int i = 1; i <= n; i++) {
			x = z = "";
			finds(a1, re[i][1]);
			if (b1 == x + re[i][2] + z) {
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
