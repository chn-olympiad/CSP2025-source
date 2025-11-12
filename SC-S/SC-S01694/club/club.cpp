#include <bits/stdc++.h>
#define fup(i, l, r) for (int i = (l); i <= (r); i++)
#define fdw(i, l, r) for (int i = (l); i >= (r); i--)
using lld = long long;
const int N = 100005, INF = 1e9;
int T, n, A[N][3], val[N];
std::vector<int> buc[3];
void solve() {
	lld ans = 0;
	scanf("%d", &n);
	fup(j, 0, 2) buc[j].resize(0);
	fup(i, 1, n) {
		int mx = -1;
		fup(j, 0, 2) {
			scanf("%d", &A[i][j]);
			if (!~mx || A[i][j] > A[i][mx]) mx = j;
		}
		buc[mx].push_back(i);
		ans += A[i][mx];
	}
	int D = -1;
	fup(j, 0, 2)
		if ((int)buc[j].size() > n / 2)
			D = j;
	if (!~D) return printf("%lld\n", ans), void();
	fup(i, 1, n) {
		val[i] = -A[i][D];
		A[i][D] = -INF;
		val[i] += std::max({ A[i][0], A[i][1], A[i][2] });
	}
	std::sort(buc[D].begin(), buc[D].end(), [](int x, int y) { return val[x] > val[y]; });
	int lim = buc[D].size() - n / 2;
	fup(i, 0, lim - 1) {
		ans += val[buc[D][i]];
	}
	printf("%lld\n", ans);
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T--) solve();
	fclose(stdin), fclose(stdout);
	return 0;
}