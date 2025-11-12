// 苦心人，天不负，加油！ 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 501000;

struct Node {
	int val = 0;
	int l, r, f;
	int al, ar;
} tree[N * 2];

ll n, k;
ll a[N];

vector<array<int, 3>> v;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%lld%lld", &n, &k);
	int T = __lg(n) + 1;
	if ((1 << (T - 1)) < n) T++;
	for (int i = 1; i <= (1 << T) - 1; i++) {
		tree[i].l = i << 1;
		tree[i].r = (i << 1) | 1;
		tree[i << 1].f = tree[(i << 1) & 1].f = i;
	}
	for (int i = (1 << (T - 1)); i < (1 << T); i++) {
		tree[i].al = tree[i].ar = i + 1 - (1 << (T - 1));
	}
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		tree[(1 << (T - 1)) + i - 1].val = a[i];
		if (a[i] == k) {
			v.push_back({1, i, i});
		}
	}
	for (int d = T - 1; d >= 1; d--) {
		for (int i = 1 << (d - 1); i < (1 << d); i++) {
			tree[i].al = tree[tree[i].l].al;
			tree[i].ar = tree[tree[i].r].ar;
			tree[i].val = tree[tree[i].l].val ^ tree[tree[i].r].val;
			if (tree[i].val == k) {
				v.push_back({min((ll)tree[i].ar, n) - tree[i].al + 1, tree[i].al, min((ll)tree[i].ar, n)});
			}
		}
	}
	for (int i = 1; i < (1 << T); i++) {
		int f = tree[i].f;
		if (tree[f].l == i) {
			int res = 0;
			while (f > 1 && tree[tree[f].f].l == f) {
				f = tree[f].f;
				res = tree[f].val ^ tree[i].val;
				if (res == k) {
					v.push_back({min((ll)tree[f].ar, n) - tree[i].ar, tree[i].ar + 1, min((ll)tree[f].ar, n)});
				}
			}
		} else {
			int res = 0;
			while (f > 1 && tree[tree[f].f].r == f) {
				f = tree[f].f;
				res = tree[f].val ^ tree[i].val;
				if (res == k) {
					v.push_back({tree[i].al - tree[f].al, tree[f].al, tree[i].al - 1});
				}
			}
		}
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	ll ans = 0;
	int len = v.size(), to = 0;
	for (int i = 0; i < len; i++) {
		while (i < len && v[i][1] <= to) {
			i++;
		}
		if (i == len) {
			break;
		}
		int f = 1;
		if (f) {
			to = v[i][2];
			ans++;
		}
	}
	printf("%lld\n", ans);
}
