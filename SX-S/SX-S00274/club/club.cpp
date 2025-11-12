#include <bits/stdc++.h>
using namespace std;

struct A {
	int a, b, w;
	int id;
} e[100005];
int q[4];

bool cmp(A x, A y) {
	return x.a + y.b > y.a + x.b;
}

void f(int n) {
	memset(q, 0, sizeof q);
	sort(e + 1, e + n + 1, cmp);
	long long ans = 0;
	for ( int i = 1 ; i <= n ; i ++ ) {
		if ( q[e[i].id] < n / 2 ) {
			ans += e[i].a;
			q[e[i].id] += 1;
		} else {
			ans += e[i].b;
		}
	}
	printf("%lld\n", ans);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while ( T-- ) {
		int n;
		scanf("%d", &n);
		for ( int i = 1 ; i <= n ; i ++ ) {
			scanf("%d %d %d", &e[i].a, &e[i].b, &e[i].w);
			e[i].id = 1;
			if ( e[i].a < e[i].b ) {
				swap(e[i].a, e[i].b);
				e[i].id = 2;
			}
			if ( e[i].a < e[i].w ) {
				swap(e[i].a, e[i].w);
				e[i].id = 3;
			}
			if ( e[i].b < e[i].w ) {
				swap(e[i].b, e[i].w);
			}
		}
		f(n);
	}
	return 0;
}