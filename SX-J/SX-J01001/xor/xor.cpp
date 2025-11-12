#include <bits/stdc++.h>
using namespace std;
long long a[500009];

struct PII {
	int l, r;
} b[100009];

bool cmp(PII p1, PII p2) {
	return p1.r < p2.r;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n;
	long long k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int t = 0;
	long long chu = a[1];
	for (int l = 1; l <= n; l++) {
		chu = a[l];
		if (chu == k) {
			t++;
			b[t].l = l;
			b[t].r = l;
		}
		for (int r = l + 1; r <= n; r++) {
			chu = chu ^a[r];
			if (chu == k) {
				t++;
				b[t].l = l;
				b[t].r = r;
			}
		}
	}
	sort(b + 1, b + t + 1, cmp);
	/*for (int i = 1; i <= t; i++) {
		cout << b[i].l << " " << b[i].r << endl;
	}
	cout << endl << b[1].l << " " << b[1].r << endl;*/
	int ans = 1;
	int l = b[1].r, h = 1;
	while (l < n && h < t) {
		h++;
		if (b[h].l > l) {
			ans++;
			l = b[h].r;
			//cout << b[h].l << " " << b[h].r << endl;
		}
	}
	cout << ans;
	return 0;
}
