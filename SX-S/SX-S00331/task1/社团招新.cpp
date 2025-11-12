#include <bits/stdc++.h>
using namespace std;

int t, n, q = 1;
int a[100005], b[100005], c[100005], d[100005];
int maxn = 0, Maxn = 0;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t > 0) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[j];
				if (maxn <= a[j]) {
					maxn = a[j];
					b[i] = maxn;
				}
			}
			c[i] = b[i];
			maxn = 0;
			b[i] = 0;
		}
		for (int k = 1; k <= n; k++) {
			Maxn += c[k];
			d[q] = Maxn;
		}
		Maxn = 0;
		q++;
		t--;
	}
	for (int i = 1; i <= q; i++) {
		cout << d[i] << endl;
	}
	return 0;
}
