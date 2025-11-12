#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
long long fwsedt, n, ans, all[4];

struct point {
	long long a, b;
	bool operator<(const point &A) const {
		return a > A.a;
	}
} a[N][13];

struct ask {
	long long data, to, p;
	bool operator<(const ask &A) const {
		return data > A.data;
	}
} b, c;

priority_queue<ask, vector<ask>> q[4];

void ipush(int f) {
	c.data  = a[f][1].a - a[f][2].a;
	c.to = 2;
	c.p = f;
	q[a[f][1].b].push(c);
}

void jump(int k) {
	int f = q[k].top().p, t = q[k].top().to;
	ans -= q[k].top().data;
	q[k].pop();
	--all[k];
	if (t == 2) {
		c.data = a[f][2].a - a[f][3].a;
		c.to = 3;
		c.p = f;
		q[a[f][2].b].push(c);
		if ((++all[a[f][2].b]) * 2 > n)
			jump(a[f][2].b);
	}
}

void solve() {
	scanf("%lld", &n);
	ans = 0;
	all[1] = 0;
	all[2] = 0;
	all[3] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%lld%lld%lld", &a[i][1].a, &a[i][2].a, &a[i][3].a);
		a[i][1].b = 1;
		a[i][2].b = 2;
		a[i][3].b = 3;
		sort(a[i] + 1, a[i] + 4);
		ans += a[i][1].a;
		ipush(i);
		if ((++all[a[i][1].b]) * 2 > n) {
			jump(a[i][1].b);
		}
	}
	printf("%lld\n", ans);
	for (int i = 1; i <= 3; i++) {
		while (!q[i].empty())
			q[i].pop();
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	scanf("%lld", &fwsedt);
	for (int i = 1; i <= fwsedt; i++)
		solve();

	return 0;
}
