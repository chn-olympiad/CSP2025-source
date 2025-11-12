#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, a[50005], aans;

struct node {
	ll l, r, mmax, sum;
} tree[500005];

inline void build(ll i, ll l, ll r) {
	tree[i] = {l, r, 0, 0};
	if (l == r) {
		tree[i].mmax = a[l];
		tree[i].sum = a[l];
		return;
	}
	ll mid = (l + r ) >> 1;
	build(i * 2, l, mid);
	build(i * 2 + 1, mid + 1, r);
	tree[i].mmax = max(tree[i * 2].mmax, tree[i * 2 + 1].mmax);
	tree[i].sum = tree[i * 2].sum + tree[i * 2 + 1].sum;
}

inline ll querymax(ll i, ll l, ll r) {
	if (tree[i].l >= l and tree[i].r <= r) {
		return tree[i].mmax;
	}
	ll mid = (tree[i].l + tree[i].r) >> 1;
	ll ans = INT_MIN;
	if (mid >= l)
		ans = max(ans, querymax(i * 2, l, r));
	if (mid + 1 <= r)
		ans = max(ans, querymax(i * 2 + 1, l, r));
	return ans;
}

inline ll querysum(ll i, ll l, ll r) {
	if (tree[i].l >= l and tree[i].r <= r) {
		return tree[i].sum;
	}
	ll mid = (tree[i].l + tree[i].r ) >> 1;
	ll ans = 0;
	if (mid >= l)
		ans += querysum(i * 2, l, r);
	if (mid + 1 <= r)
		ans += querysum(i * 2 + 1, l, r);
	return ans;
}

int main() {

	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build(1, 1, n);
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			ll sum = querysum(1, i, j);
			ll mmax = querymax(1, i, j);
			if (sum > mmax * 2)
				aans++;
		}
	}
	cout << aans;

	return 0;
}
