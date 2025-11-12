#include <bits/stdc++.h>
using namespace std;

int n, a[500010] = {0}, k, cnt, t = -1, ans;
struct node {
	int l, r;
} e[1000005];
map<int, bool> mp;
bool cmp(node x, node y) {
	return x.r < y.r;
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] = a[i - 1] ^ a[i];
	}
	for (int i = 0; i <= n; i++) {
		int f = a[i] ^ k;
		for (int j = i + 1; j <= n; j++) {
			if (a[j] == f) {
				e[++cnt] = {i + 1, j};
				break;
			}
		}
	}
	sort(e + 1, e + cnt + 1, cmp);
	for (int i = 1; i <= cnt; i++) {
		if (e[i].l <= t)
			continue;
		else {
			ans++;
			t = e[i].r;
		}
	}
	cout << ans;
	return 0;
}
