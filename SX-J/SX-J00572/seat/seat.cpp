#include <bits/stdc++.h>
using namespace std;

struct lx {
	long long id, f;
} a[105];
long long n, m;

bool cmp(lx s1, lx s2) {
	return s1.f > s2.f;
}

int main() {
	//¼ì²é×¢ÊÍ
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	long long nm = n * m;
	for (int i = 1; i <= nm; i++) {
		scanf("%lld", &a[i].f);
		a[i].id = i;
	}
	sort(a + 1, a + nm + 1, cmp);
	long long x = 1, y = 1, i = 1;
	while (a[i].id != 1) {
		i++;
		if ((y == 1) && (x % 2 == 0)) {
			x++;
		} else if ((y == n) && (x % 2 == 1)) {
			x++;
		} else if (x % 2 == 0) {
			y--;
		} else if (x % 2 != 0) {
			y++;
		}
		//printf("%lld %lld %lld\n", x, y, i);
	}
	printf("%lld %lld", x, y);
	fclose(stdin);
	fclose(stdout);
	return 0;
}