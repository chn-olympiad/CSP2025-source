#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
LL res; 
const int N = 100010;
struct Node {
	LL idx, v, p, d;
	bool operator<(const Node& W) const {
		if (idx != W.idx) return idx > W.idx;
		return v > W.v; 
	}
} q[N << 2]; int cnt;
int c[5];
bool st[N];
int n;
PII a[N][5];
bool cmp(PII a, PII b) {
	if (a.first != b.first) return a.first > b.first;
	return a.second < b.second; 
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T; scanf("%d", &T);
	while (T -- ) {
		scanf("%d", &n); cnt = 0;
		for (int i = 1; i <= n; i ++ ) st[i] = false;
		for (int i = 1; i <= 3; i ++ ) c[i] = 0;
		for (int i = 1; i <= n; i ++ ) {
			for (int j = 1, x; j <= 3; j ++ ) scanf("%d", &x), a[i][j] = {x, j};
			sort(a[i] + 1, a[i] + 3 + 1, cmp);
			//cout << a[i][1].first << ' ' << a[i][2].first << endl;
			for (int j = 1; j < 2; j ++ ) q[ ++ cnt] = {a[i][j].first - a[i][j + 1].first, a[i][j].first, i, a[i][j].second};
		}
		sort(q + 1, q + cnt + 1);
		LL res = 0;
		for (int i = 1; i <= cnt; i ++ ) {
			int v = q[i].v, p = q[i].p, d = q[i].d;
			if (st[p] || (c[d] >= n / 2)) continue;
			c[d] ++ , st[p] = true;
			res += v;
		}
		cnt = 0;
		for (int i = 1; i <= n; i ++ ) {
			for (int j = 2; j < 3; j ++ ) q[ ++ cnt] = {a[i][j].first - a[i][j + 1].first, a[i][j].first, i, a[i][j].second};
		}
		for (int i = 1; i <= cnt; i ++ ) {
			int v = q[i].v, p = q[i].p, d = q[i].d;
			if (st[p] || (c[d] >= n / 2)) continue;
			c[d] ++ , st[p] = true;
			res += v;
		}
		printf("%lld\n", res);	
	}
	return 0;
}
