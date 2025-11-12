#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 15;
int t;
int n;
int ans;
struct Club {
	int d1, d2, d3;
	int Max, Maxid, Mid, Midid, Min, Minid;
	int vis;
} a[maxn];
bool cmp(Club a, Club b) {
	return a.Max > b.Max;
}
void Read();

int main() {

	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	scanf("%d", &t);
	while (t--) {
		ans = 0;
		Read();
		sort(a + 1, a + n + 1, cmp);
		int cnt[5] = {0, 0, 0, 0, 0};
		for (int i = 1; i <= n; i++) {
			ans += a[i].Min;
			if (cnt[a[i].Maxid] >= n / 2) {
				ans += a[i].Mid;
				cnt[a[i].Midid]++;
			} else {
				ans += a[i].Max;
				cnt[a[i].Maxid]++;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}

void Read() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &a[i].d1, &a[i].d2, &a[i].d3);
		a[i].Min = min({a[i].d1, a[i].d2, a[i].d3});
		a[i].d1 -= a[i].Min;
		a[i].d2 -= a[i].Min;
		a[i].d3 -= a[i].Min;
		a[i].Max = max({a[i].d1, a[i].d2, a[i].d3});
		if (a[i].d1 == a[i].Max) {
			a[i].Maxid = 1;
			if (a[i].d2) {
				a[i].Mid = a[i].d2;
				a[i].Midid = 2;
				a[i].Minid = 3;
			} else {
				a[i].Mid = a[i].d3;
				a[i].Midid = 3;
				a[i].Minid = 2;
			}
		} else if (a[i].d2 == a[i].Max) {
			a[i].Maxid = 2;
			if (a[i].d1) {
				a[i].Mid = a[i].d1;
				a[i].Midid = 1;
				a[i].Minid = 3;
			} else {
				a[i].Mid = a[i].d3;
				a[i].Midid = 3;
				a[i].Minid = 1;
			}
		} else if (a[i].d3 == a[i].Max) {
			a[i].Maxid = 3;
			if (a[i].d1) {
				a[i].Mid = a[i].d1;
				a[i].Midid = 1;
				a[i].Minid = 2;
			} else {
				a[i].Mid = a[i].d2;
				a[i].Midid = 2;
				a[i].Minid = 1;
			}
		}
	}
}
