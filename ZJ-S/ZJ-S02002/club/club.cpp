#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 6;
int n, a[N][4], cnta, cntb, cntc, ans, top, T;
vector <int> va, vb, vc;
struct Node {
	int id, val;
} b[N];
bool cmp(Node x, Node y) {
	return x.val > y.val;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		ans = 0;
		for (int i = 1; i <= n; ++i) b[i] = {0, 0};
		cnta = cntb = cntc = top = 0;
		va.clear(), vb.clear(), vc.clear();
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
		for (int i = 1; i <= n; ++i) {
			if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) {
				ans += a[i][1];
				++cnta;
				va.push_back(i);
			} else if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) {
				ans += a[i][2];
				++cntb;
				vb.push_back(i);
			} else {
				ans += a[i][3];
				++cntc;
				vc.push_back(i);
			}
		}
		if (cnta > n / 2) {
			for (int i = 0; i < va.size(); ++i)
				b[++top] = {i, max(a[va[i]][2], a[va[i]][3]) - a[va[i]][1]};
			sort(b + 1, b + top + 1, cmp);
			for (int i = 1; i <= cnta - (n / 2); ++i)
				ans += b[i].val;
		} else if (cntb > n / 2) {
			for (int i = 0; i < vb.size(); ++i)
				b[++top] = {i, max(a[vb[i]][1], a[vb[i]][3]) - a[vb[i]][2]};
			sort(b + 1, b + top + 1, cmp);
			for (int i = 1; i <= cntb - (n / 2); ++i)
				ans += b[i].val;
		} else if (cntc > n / 2) {
			for (int i = 0; i < vc.size(); ++i)
				b[++top] = {i, max(a[vc[i]][1], a[vc[i]][2]) - a[vc[i]][3]};
			sort(b + 1, b + top + 1, cmp);
			for (int i = 1; i <= cntc - (n / 2); ++i)
				ans += b[i].val;
		}
		printf("%d\n", ans);
	}
	return 0;
}
