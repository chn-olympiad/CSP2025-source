#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int T, n;
struct info {
	int a[5], d, maid, tmaid;
	bool operator < (const info &A) const {
		return A.d < d;
	}
} a[N];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			for(int j = 0; j < 3; j++)
				scanf("%d", &a[i].a[j]);
			if(a[i].a[0] >= a[i].a[1] && a[i].a[1] >= a[i].a[2]) a[i].maid = 0, a[i].tmaid = 1;
			if(a[i].a[0] >= a[i].a[2] && a[i].a[2] >= a[i].a[1]) a[i].maid = 0, a[i].tmaid = 2;
			if(a[i].a[1] >= a[i].a[0] && a[i].a[0] >= a[i].a[2]) a[i].maid = 1, a[i].tmaid = 0;
			if(a[i].a[1] >= a[i].a[2] && a[i].a[2] >= a[i].a[0]) a[i].maid = 1, a[i].tmaid = 2;
			if(a[i].a[2] >= a[i].a[0] && a[i].a[0] >= a[i].a[1]) a[i].maid = 2, a[i].tmaid = 0;
			if(a[i].a[2] >= a[i].a[1] && a[i].a[1] >= a[i].a[0]) a[i].maid = 2, a[i].tmaid = 1;
			a[i].d = a[i].a[a[i].maid] - a[i].a[a[i].tmaid];
		}
		sort(a + 1, a + n + 1);
//		for(int i = 1; i <= n; i++)
//			printf("%d %d %d %d %d %d\n", a[i].a[0], a[i].a[1], a[i].a[2], a[i].d, a[i].maid, a[i].tmaid);
		int cnt[5], res = 0; cnt[0] = cnt[1] = cnt[2] = 0;
		for(int i = 1; i <= n; i++) {
			if(cnt[a[i].maid] + 1 > n / 2) {
				++cnt[a[i].tmaid];
				res += a[i].a[a[i].tmaid];
			} else {
				++cnt[a[i].maid];
				res += a[i].a[a[i].maid];
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
