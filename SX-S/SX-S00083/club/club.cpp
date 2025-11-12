#include <bits/stdc++.h>
using namespace std;
#define N 100100
typedef long long ll;
int T, n, a[3][N], sta[3][N], top[3], con[N], b[N];
ll ans = 0;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		ans = 0;
		top[0] = top[1] = top[2] = 0;
		for (int i = 1; i <= n; i++) {
			int mp = 0;
			for (int j = 0; j < 3; j++) {
				scanf("%d", a[j] + i);
				if (a[j][i] > a[mp][i])
					mp = j;
			}
			ans += a[mp][i];
			sta[mp][++top[mp]] = i;
			con[i] = (a[mp][i] -
			          max(a[(mp + 1) % 3][i], a[(mp + 2) % 3][i]));
		}
		int mp = 0;
		if (top[1] > top[mp])
			mp = 1;
		if (top[2] > top[mp])
			mp = 2;
		if (top[mp] * 2 <= n)
			printf("%lld\n", ans);
		else {
			for (int i = 1; i <= top[mp]; i++)
				b[i] = con[sta[mp][i]];
			sort(b + 1, b + 1 + top[mp]);
			for (int i = 1; i <= top[mp] - (n / 2); i++)
				ans -= b[i];
			printf("%lld\n", ans);
		}
	}
	return 0;
}
