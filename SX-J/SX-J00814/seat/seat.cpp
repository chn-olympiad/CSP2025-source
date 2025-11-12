#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, pm;

struct node {
	ll id, score;
} a[1010];

bool cmp(node x, node y) {
	return x.score > y.score;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i].score;
		a[i].id = i;
	}
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i].id == 1) {
			pm = i;
		}
	}
	ll x, y = (pm - 1) / n + 1;
	if (y % 2 == 1) {
		if (pm % n == 0) {
			x = n;
		} else {
			x = pm % n;
		}
	} else {
		if (pm % n == 0) {
			x = 1;
		} else {
			x = n - pm % n + 1;
		}
	}
	cout << y << " " << x;
	return 0;
}
