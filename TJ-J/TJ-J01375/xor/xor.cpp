#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define int long long
const int maxn = 5e5 + 8;
int n, k, a[maxn], sum[maxn], ans, tot;
struct node {
	int l, r;
	bool operator < (const node &rhs) const {
		if (r != rhs.r) return r < rhs.r;
		return l < rhs.l;
	}
} b[maxn];
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	bool flag = true;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] ^ a[i];
	}
	for (int l = 1; l <= n; l++) {
		for (int r = l; r <= n; r++) {
			int res = sum[r] ^ sum[l - 1];
			if (res == k) {
				node cur;
				cur.l = l, cur.r = r;
				b[++tot] = cur;
			}
		}
	}
	if (tot != 0) {
		ans = 1;
	}
	sort(b + 1, b + tot + 1);
	int lst = b[1].r;
	for (int i = 2; i <= tot; i++) {
		if (b[i].l > lst) {
			ans++;
			lst = b[i].r;
		}
	}
	cout << ans;
	return 0;
}
