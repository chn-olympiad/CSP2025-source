#include <bits/stdc++.h>
#define N 1000005
#define ll long long
using namespace std;

ll a[N], tr[N], n, m, ans;

struct qj {
	ll l, r;
} f[N];

bool cmp(qj x, qj y) {
	if (x.r != y.r)
		return x.r < y.r;
	else
		return x.l < y.l;

}

ll lowbit(ll x) {
	return (x&(-x));
}

void add(ll x, ll id) {
	for (int i = id; i <= n; i += lowbit(i)) {
		tr[i] ^= x;
	}
	return ;
}

ll ask(ll id) {
	ll sum = 0;
	for (int i = id; i >= 1; i -= lowbit(i)) {
		sum = sum ^tr[i];
	}
	return sum;
}

void slove(ll nn) {
	qj x;
	x.l = f[1].l, x.r = f[1].r ;
	for (ll i = 2; i <= nn; i++) {

		if (f[i].l > x.r  ) {
			ans++;
			x.r = f[i].r;
//			cout << f[i].l << " " << f[i].r << "\n";
		}
	}
}

int main() {

	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
//	cout << "Hi word\n";

	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		add(a[i], i);

	}

	ll  tot = 0;
//	cout << (ask(3));
	for (ll i = 1; i <= n; i++) {
		if (a[i] == m)
			f[++tot].l = i, f[tot].r = i;
		for (ll j = i + 1; j <= n; j++) {
			ll x = (ask(j)^ask(i - 1));
			if (x == m) {

				f[++tot].l = i, f[tot].r = j;
//				cout << i << " " << j << '\n';
//				cout << (ask(j)^ask(i - 1)) << "   ";
			}
		}

	}
	sort(f + 1, f + tot + 1, cmp);
	if (tot >= 1)
		ans++;
	slove(tot);

	cout << ans;
	return 0;
}














