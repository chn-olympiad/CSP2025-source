#include <bits/stdc++.h>
using namespace std;
int T, lo[100005];

struct node {
	int a, b, c;
} s[100005];

bool cmp1(node x, node y) {
	return max(x.b, x.c) > max(y.b, y.c);
}

bool cmp2(node x, node y) {
	return max(x.a, x.c) > max(y.a, y.c);
}

bool cmp3(node x, node y) {
	return max(x.a, x.b) > max(y.a, y.b);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		int n, maxxx = -1, maxn = 0, b1 = 0, b2 = 0, b3 = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			maxxx = -1;
			scanf("%d%d%d", &s[i].a, &s[i].b, &s[i].c);
			maxxx = max(maxxx, max(s[i].a, max(s[i].b, s[i].c)));
			if (maxxx == s[i].a) {
				b1++;
				lo[i] = 1;
			} else if (maxxx == s[i].b) {
				b2++;
				lo[i] = 2;
			} else {
				b3++;
				lo[i] = 3;
			}
			maxn += maxxx;
		}
		if (b1 <= n / 2 && b2 <= n / 2 && b3 <= n / 2)
			cout << maxn << endl;
		else {
//			cout << b1 << " " << b2 << " " << b3 << endl << endl;
			bool flaga = 0, flagb = 0, flagc = 0;
			for (int i = 1; i <= n; i++) {
				int maxx = -1;
				maxx = max(s[i].a, max(s[i].b, s[i].c));
				s[i].a = s[i].a - maxx, s[i].b = s[i].b - maxx, s[i].c = s[i].c - maxx;
			}
//			cout << maxn << endl;
			if (b1 <= n / 2)
				flaga = 1;
			if (b2 <= n / 2)
				flagb = 1;
			if (b3 <= n / 2)
				flagc = 1;

			if (flaga == 0)
				sort(s + 1, s + n + 1, cmp1);
			else if (flagb == 0)
				sort(s + 1, s + n + 1, cmp2);
			else
				sort(s + 1, s + n + 1, cmp3);
			for (int i = 1; i <= n; i++) {

				if (b1 <= n / 2 && b2 <= n / 2 && b3 <= n / 2)
					break;
				if (flaga == 0) {
					if (s[i].a != 0)
						continue;
					if (s[i].b > s[i].c) {
						b1--, b2++;
						maxn += s[i].b;
					} else {
						b1--, b3++;
						maxn += s[i].c;
					}
				} else if (flagb == 0) {
					if (s[i].b != 0)
						continue;
					if (s[i].a > s[i].c) {
						b2--, b1++;
						maxn += s[i].a;
					} else {
						b2--, b3++;
						maxn += s[i].c;
					}
				} else {
					if (s[i].c != 0)
						continue;
					if (s[i].a > s[i].b) {
						b3--, b1++;
						maxn += s[i].a;
					} else {
						b3--, b2++;
						maxn += s[i].b;
					}
				}
			}
			cout << maxn << endl;
		}
	}
	return 0;
}

