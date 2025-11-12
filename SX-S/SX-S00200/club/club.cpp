#include <bits/stdc++.h>
using namespace std;

struct node2 {
	int a, b, c, maxn, cha, sc;
} edge[600005];

struct node1 {
	int s, x;
} way[200005];
int d, n, num[5], minn[5], maxx[5];
long long ans = 0;

void ads(int m) {
	if (num[edge[m].maxn] == 0) {
		minn[edge[m].maxn] = m;
		maxx[edge[m].maxn] = m;
		way[m].s = m;
		way[m].x = m;
		return;
	}
	if (edge[minn[edge[m].maxn]].cha > edge[m].cha) {
		way[m].s = minn[edge[m].maxn];
		way[m].x = m;
		way[minn[edge[m].maxn]].x = m;
		minn[edge[m].maxn] = m;
		return;
	}
	if (edge[maxx[edge[m].maxn]].cha < edge[m].cha) {
		way[m].s = m;
		way[m].x = maxx[edge[m].maxn];
		way[maxx[edge[m].maxn]].s = m;
		maxx[edge[m].maxn] = m;
		return;
	}
	int j = minn[edge[m].maxn];
	while (1) {
		if (edge[m].cha <= edge[j].cha) {
			if (minn[edge[m].maxn] == j) {
				way[m].s = m;
				way[m].x = maxx[edge[m].maxn];
				way[maxx[edge[m].maxn]].s = m;
				maxx[edge[m].maxn] = m;
				return;
			}
			way[way[j].x].s = m;
			way[m].s = j;
			way[m].x = way[j].x;
			way[j].x = m;
		}
		j = way[j].s;
	}
	return;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> d;
	while (1) {
		if (d == 0) {
			break;
		}
		d--;
		ans = 0;
		for (int i = 1; i <= 5; i++) {
			num[i] = 0;
			maxx[i] = 0;
			minn[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			edge[i].a = 0;
			edge[i].b = 0;
			edge[i].c = 0;
			edge[i].cha = 0;
			edge[i].maxn = 0;
			edge[i].sc = 0;
			way[i].s = 0;
			way[i].x = 0;
		}
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> edge[i].a >> edge[i].b >> edge[i].c;
			edge[i].maxn = max(edge[i].a, max(edge[i].b, edge[i].c));
			if (edge[i].maxn == edge[i].a) {
				if (edge[i].b > edge[i].c) {
					edge[i].cha = edge[i].maxn - edge[i].b;
					edge[i].maxn = 1;
					edge[i].sc = 2;
				} else {
					edge[i].cha = edge[i].maxn - edge[i].c;
					edge[i].maxn = 1;
					edge[i].sc = 3;
				}
			} else if (edge[i].b == edge[i].maxn) {
				if (edge[i].a > edge[i].c) {
					edge[i].cha = edge[i].maxn - edge[i].a;
					edge[i].maxn = 2;
					edge[i].sc = 1;
				} else {
					edge[i].cha = edge[i].maxn - edge[i].c;
					edge[i].maxn = 2;
					edge[i].sc = 3;
				}
			} else {
				if (edge[i].a > edge[i].b) {
					edge[i].cha = edge[i].maxn - edge[i].a;
					edge[i].maxn = 3;
					edge[i].sc = 1;
				} else {
					edge[i].cha = edge[i].maxn - edge[i].b;
					edge[i].maxn = 3;
					edge[i].sc = 2;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (num[edge[i].maxn] < n / 2) {
				ans += max(edge[i].a, max(edge[i].b, edge[i].c));
				ads(i);
				num[edge[i].maxn]++;
				continue;
			}
			ads(i);
			ans += max(edge[i].a, max(edge[i].b, edge[i].c));
			int q = minn[edge[i].maxn];
			num[edge[i].sc]++;
			minn[edge[i].maxn] = way[minn[edge[i].maxn]].s;
			way[minn[edge[i].maxn]].x = minn[edge[i].maxn];
			edge[i].maxn = edge[i].sc;
			ads(q);
			ans -= edge[q].cha;
		}
		cout << ans << endl;
	}
	return 0;
}
