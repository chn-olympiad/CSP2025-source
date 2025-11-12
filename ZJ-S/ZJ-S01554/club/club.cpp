#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read() {
	ll x = 0, y = 1;
	char c = getchar();
	while (c > '9' || c < '0') {
		if (c == '-') y = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * y;
}
const int N = 1e5 + 7;
struct node{
	int a, b, c;
}p[N], l[N], r[N];
int n, t, lt, rt;
ll ans;
bool cmp_ab(node x, node y) {return (x.a - x.b) >= (y.a - y.b);}
bool cmp_a(node x, node y){return x.a >= y.a;}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	t = read();
	while (t--) {
		n = read();
		ans = 0; lt = rt = 0;
		for (int i = 1; i <= n; i++) {
			p[i].a = read(), p[i].b = read(), p[i].c = read(),
			ans += p[i].c, p[i].a -= p[i].c, p[i].b -= p[i].c;
			if (p[i].a >= 0 || p[i].b >= 0) l[++lt] = p[i];
			else r[++rt] = p[i];
		}
		sort(l + 1, l + 1 + lt, cmp_ab);
//		puts("----------");
//		for (int i = 1; i <= lt; i++)
//			printf("%d %d\n", l[i].a, l[i].b);
//		puts("----------");
//		for (int i = 1; i <= rt; i++)
//			printf("%d %d\n", r[i].a, r[i].b);
//		puts("----------");
		int c1 = 0, c2 = 0;
		for (int i = 1; i <= min(lt, n / 2) && l[i].a >= l[i].b; i++) ans += l[i].a, c1++;
		for (int i = lt; i >= max(1, lt - n / 2 + 1) && l[i].a < l[i].b; i--) ans += l[i].b, c2++;
//		printf("%lld c1 : %d c2 : %d\n", ans, c1, c2);
//		puts("--------");
		if (c1 == n / 2) for (int i = n / 2 + 1, r = lt - c2; i <= r; i++) if (l[i].b >= 0) ans += l[i].b, c2++;
		if (c2 == n / 2) for (int i = n / 2, r = c1 + 1; i >= r; i--) if (l[i].a >= 0) ans += l[i].a, c1++;
//		printf("%lld c1 : %d c2 : %d\n", ans, c1, c2);
//		puts("----------");
		if (c1 + c2 < n / 2) {
			int p = n / 2 - c1 - c2;
			for (int i = 1; i <= rt; i++) r[i].a = max(r[i].a, r[i].b);
			sort(r + 1, r + 1 + rt, cmp_a);
			for (int i = 1; i <= p; i++) ans += r[i].a;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
/*
hai zi men, wo T1 tiao le 2h.
wo hui yin ma?
suan le, tui yi yao jin.
*/
