#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
long long t, n, half, ans, sum[5];

struct node {
	long long first, second, fid, sid;
} w[N];

struct noodle {
	long long a, id;
} _x[5];

bool cmp1(noodle x, noodle y) {
	if (x.a == y.a)
		return x.id < y.id;
	return x.a > y.a;
}

bool cmp2(node x, node y) {
	if (x.first - x.second == y.first - y.second) {
		if (x.first == y.first)
			return x.second < y.second;
		return x.first > y.first;
	}
	return x.first - x.second > y.first - y.second;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%lld", &t);
	while (t--) {
		ans = sum[1] = sum[2] = sum[3] = 0;
		scanf("%lld", &n);
		half = n / 2;
		for (int i = 1; i <= n; i++) {
			scanf("%lld%lld%lld", &_x[1].a, &_x[2].a, &_x[3].a);
			_x[1].id = 1, _x[2].id = 2, _x[3].id = 3;
			sort(_x + 1, _x + 4, cmp1);
			w[i].first = _x[1].a, w[i].fid = _x[1].id, w[i].second = _x[2].a, w[i].sid = _x[2].id;
		}
		sort(w + 1, w + 1 + n, cmp2);
		for (int i = 1; i <= n; i++) {
			if (sum[w[i].fid] < half)
				ans += w[i].first, sum[w[i].fid]++;
			else
				ans += w[i].second, sum[w[i].sid]++;
		}
		printf("%lld\n", ans);
	}
	return 0;
}