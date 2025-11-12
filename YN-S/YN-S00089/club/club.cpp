#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
using LL = long long;
LL a[N];
LL b[N];
LL c[N];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		LL ans = 0;
		cin >> n;
		for (int i = 1; i <= N; i++) {
			a[i] = b[i] = c[i] = 0;
		}

		int cnta = 0, cntb = 0, cntc = 0;
		for (int i = 1; i <= n; i++) {
			LL aa, bb, cc;
			cin >> aa >> bb >> cc;
			LL Max = max(aa, max(bb, cc));
			ans += Max;
			//	cout << Max << "\n\n";
			if (Max == aa) {
				cnta++;
				if (bb > cc)
					a[cnta] = aa - bb;
				else
					a[cnta] = aa - cc;
			} else if (Max == bb) {
				cntb++;
				if (aa > cc)
					b[cntb] = bb - aa;
				else
					b[cntb] = bb - cc;
			} else if (Max == cc) {
				cntc++;
				if (bb > aa)
					c[cntc] = cc - bb;
				else
					c[cntc] = cc - aa;
			}
		}
		//cout << ans << "\n";
		for (int i = 1; i <= n; i++) {
			//	cout << a[i] << " " << b[i] << " " << c[i] << "\n";
		}
		if (cnta > n / 2) {
			sort(a + 1, a + 1 + cnta);
			for (int i = 1; i <= cnta - (n / 2); i++) {
				ans -= a[i];
			}
		}
		if (cntb > n / 2) {
			sort(b + 1, b + 1 + cntb);
			for (int i = 1; i <= cntb - (n / 2); i++) {
				ans -= b[i];
			}
		}
		if (cntc > n / 2) {
			sort(c + 1, c + 1 + cntc);
			for (int i = 1; i <= n; i++) {
				//		cout << c[i] << " ";
			}
			for (int i = 1; i <= cntc - (n / 2); i++) {
				ans -= c[i];
				//	cout << c[i];
			}
		}
		cout << ans << "\n";
	}
	return 0;
}