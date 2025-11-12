/*
T2 road
连通无向图
所有边被破坏了，修复第 i条道路的费用为 wi
有 k 个准备进行城市化改造的乡镇
第 j个乡镇费用为 cj
改造完第 j (1 ≤ j ≤ k) 个乡镇后，可以 与原来的 n 座城市间建造若干条道路
与第 i 座城市间建造一条道路的费用为 aj,i。
可以选择任意若干城市改造，可以不改造
求连通最小费用
*/
#include <bits/stdc++.h>
using namespace std;
#define _for(i, a, b) for(int i = (a); i <= (b); ++i)
#define _rfo(i, a, b) for(int i = (a); i >= (b); --i)
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFO(i, a, b) for(int i = (a); i > (b); --i)
using LL = long long;
using VI = vector<int>;
const int NN = 1E6 + 5, NN1 = 1E4 + 5;

struct DSU {
	int n, Fa[NN];
	void init(int _n) {
		n = _n;
		iota(Fa, Fa + n + 1, 0);
	}
	int Find(int x) {
		return Fa[x] == x ? x : Fa[x] = Find(Fa[x]);
	}
	void Merge(int u, int v) {
		int fu = Find(u), fv = Find(v);
		if (fu != fv)
			Fa[fu] = fv;
	}
} D;
array<LL, 3> Es[NN * 2], Tmp[NN * 2];
LL A[15][NN1], C[15], ans = 0x3f3f3f3f;
int n, m, k;

void dfs(int t = 1, int pre = 0, LL cst = 0) {
	if (t == k + 1) {
		D.init(n + k);
		m += pre * n;
		_for(j, 1, m) Tmp[j] = Es[j];
		sort(Tmp + 1, Tmp + 1 + m);
		_for(i, 1, m) {
			int u = Tmp[i][1], v = Tmp[i][2];
			if (D.Find(u) == D.Find(v))
				continue;
			cst += Tmp[i][0], D.Merge(u, v);
		}
		ans = min(ans, cst), m -= pre * n;
		return;
	}
	dfs(t + 1, pre, cst);
	_for(i, 1, n) Es[m + pre * n + i] = {A[t][i], n + t, i};
	dfs(t + 1, pre + 1, cst + C[t]);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	_for(i, 1, m) scanf("%lld%lld%lld", &Es[i][1], &Es[i][2], &Es[i][0]);
	_for(i, 1, k) {
		cin >> C[i];
		_for(j, 1, n) cin >> A[i][j];
	}
	dfs();
	cout << ans;
	return 0;
}