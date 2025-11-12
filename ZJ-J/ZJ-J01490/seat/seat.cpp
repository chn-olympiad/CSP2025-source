#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N = 1e4 + 5;
ll n, m, x, t, top, c, r;
char s[N];
set <ll> a;

int main() {
//	freopen("number.in", "number", stdin);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n * m; ++i) {
		scanf("%lld", &t);
		a.insert(t);
		if (i == 1)
			x = t;
	}
	while (1) {
		++top;
		if (*a.begin() == x)
			break;
		a.erase(*a.begin());
	}
	top = n * m - top + 1;
//	printf("top = %lld, ", top);
	if (top % n == 0) {
		c = top / n;
		printf("%lld ", c);
		if (c % 2 == 1)
			printf("1");
		else
			printf("%lld", n);
		return 0;
	} else {
		x = top % n;
		c = top / n + 1;
		printf("%lld ", c);
		if (c % 2 == 1)
			r = x;
		else
			r = n - x + 1;
		printf("%lld", r);
	}
}/*

*/
