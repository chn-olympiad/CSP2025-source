#include <bits/stdc++.h>
using namespace std;
long long n, a[5005], sum, mmax, ans;

/*
struct {
	int l, r, lazy;
	long long sum, mmax;
} tree[20005];

inline void build(int i, int L, int R) {
	tree[i].l = L;
	tree[i].r = R;
	tree[i].sum = 0;
	if (L == R) {
		tree[i].sum = tree[i].mmax = a[L];
		return ;
	}
	int mid = tree[i].l + tree[i].r >> 1;
	build(2 * i, tree[i].l, mid);
	build(2 * i + 1, mid + 1, tree[i].r);
	tree[i].sum = tree[2*i].sum +tree[2*i+1].sum;
	tree[i].mmax = tree[2*i].mmax +tree[2*i+1].mmax;
}
*/
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	stable_sort(a + 1, a + n + 1);
	if (a[1] == a[n]) {
		for (int i = 1; i <= n; i++) {
			ans = ans % 998244353 + i;
		}
		cout << ans;
		return 0;
	} else if (n <= 3) {
		if (a[1] + a[2] + a[3] > a[3] * 2)
			cout << 1;
		else
			cout << 0;
	}




	return 0;
}
