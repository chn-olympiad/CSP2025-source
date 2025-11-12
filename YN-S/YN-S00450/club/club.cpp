#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 10;

struct node {
	ll a, b, c;
	ll cha;
	ll great;
	ll greatno;
	ll second;
	ll secondno;
};
ll n, T;
node arr[N];
ll cnt[5];

node ffind(node x) {
	if (x.a >= x.b && x.a >= x.c) {
		x.cha = min(x.a - x.b, x.a - x.c);
		x.great = x.a;
		x.greatno = 1;
		if (x.b > x.c) {
			x.second = x.b;
			x.secondno = 2;
		} else {
			x.second = x.c;
			x.secondno = 3;
		}
	}
	if (x.b >= x.a && x.b >= x.c) {
		x.cha = min(x.b - x.a, x.b - x.c);
		x.great = x.b;
		x.greatno = 2;
		if (x.a > x.c) {
			x.second = x.a;
			x.secondno = 1;
		} else {
			x.second = x.c;
			x.secondno = 3;
		}
	}
	if (x.c >= x.b && x.c >= x.a) {
		x.cha = min(x.c - x.a, x.c - x.b);
		x.great = x.c;
		x.greatno = 3;
		if (x.b > x.a) {
			x.second = x.b;
			x.secondno = 2;
		} else {
			x.second = x.a;
			x.secondno = 1;
		}
	}
	return x;
}

bool cmp(node x, node y) {
	if (x.cha == y.cha) {
		return x.great > y.great;
	}
	return x.cha > y.cha;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%lld", &T);
	while (T--) {
		ll ans = 0;
		scanf("%lld", &n);
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; i++) {
			scanf("%lld%lld%lld", &arr[i].a, &arr[i].b, &arr[i].c);
			arr[i] = ffind(arr[i]);
		}
		sort(arr + 1, arr + n + 1, cmp);
		for (int i = 1; i <= n; i++) {
			if (cnt[arr[i].greatno] + 1 > n / 2) {
				ans += arr[i].second;
				cnt[arr[i].secondno]++;
			} else {
				ans += arr[i].great;
				cnt[arr[i].greatno]++;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}