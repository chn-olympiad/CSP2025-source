#include <bits/stdc++.h>
using namespace std;
int n, k, a[500005], ans = 0, x, cnt = 1, sum = 0;
bool w = 1, w1 = 0, w2 = 0;

struct my {
	int l, r;
	bool q = 0;
} qc[500005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > 1)
			w = 0;
		if (a[i] == 1 && i > 1 && a[i - 1] == 0)
			w1 = 1;
		if (a[i] == 0 && i > 1 && a[i - 1] == 1)
			w2 = 1;
		if (a[i] == 1)
			sum += a[i];
	}
	if (sum == n) {
		cout << 1;
		return 0;
	}
	if (w) {
		cout << w1 + w2;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		x = a[i];
		for (int j = i; j <= n; j++) {
			if (i != j)
				x = (x ^ a[j]);
			if (x == k) {
				qc[cnt].l = i;
				qc[cnt].r = j;
				qc[cnt].q = 1;
				cnt++;
			}
		}
	}
	for (int i = 1; i < cnt; i++) {
		for (int j = i + 1; j < cnt; j++) {
			if (qc[i].q && qc[j].q) {
				if (qc[i].l == qc[j].l)
					qc[j].q = 0;
				if (qc[i].r == qc[j].r)
					qc[j].q = 0;
			}
		}
	}
	for (int i = 1; i < cnt; i++) {
		ans += int(qc[i].q);
	}
	cout << ans;
	return 0;
}