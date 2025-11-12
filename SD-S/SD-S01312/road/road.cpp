#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

namespace PTqwq {
	
int readqwq() {
	int x = 0;
	bool f = false;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar()) f |= (c == '-');
	for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) + (c - '0');
	if (f) {
		x = -x;
	}
	return x;
}

ll readllqwq() {
	ll x = 0;
	bool f = false;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar()) f |= (c == '-');
	for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) + (c - '0');
	if (f) {
		x = -x;
	}
	return x;
}

const int N = 2e4 + 50;
const int M = 1e6 + 50;
const ll infLL = 1e18;

int n, m, k, ord1[M], ord2[M], ord3[M];
int infoU[M], infoV[M];
ll infoW[M];
int curU[M], curV[M];
ll curW[M];
ll valC[16], valA[16][N];
int dsu[N], nowSiz[N];

int findFa(int x) {
	return dsu[x] == x ? x : dsu[x] = findFa(dsu[x]);
}
bool LinkE(int x, int y) {
	x = findFa(x);
	y = findFa(y);
	if (x != y) {
		if (nowSiz[x] > nowSiz[y]) {
			swap(x, y);
		}
		dsu[x] = y;
		nowSiz[y] += nowSiz[x];
		return true;
	}
	return false;
}

void Solve() {
	n = readqwq();
	m = readqwq();
	k = readqwq();
	for (int i = 1; i <= m; ++ i) {
		infoU[i] = readqwq();
		infoV[i] = readqwq();
		infoW[i] = readllqwq();
	}
	for (int i = 0; i < k; ++ i) {
		valC[i] = readllqwq();
		for (int j = 1; j <= n; ++ j) {
			valA[i][j] = readllqwq();
		}
	}
	
	for (int i = 1; i <= m; ++ i) {
		ord1[i] = i;
	}
	sort(ord1 + 1, ord1 + 1 + m, [&](int u, int v) {
		return infoW[u] < infoW[v];
	});
	int cntE = 0;
	for (int i = 1; i <= n; ++ i) {
		dsu[i] = i; nowSiz[i] = 1;
	}
	for (int i = 1; i <= m && cntE < n - 1; ++ i) {
		if (LinkE(infoU[ord1[i]], infoV[ord1[i]])) {
			ord2[++ cntE] = ord1[i];
		}
	}
	
	for (int j = 1; j <= cntE; ++ j) {
		ord3[j] = j;
		curU[j] = infoU[ord2[j]];
		curV[j] = infoV[ord2[j]];
		curW[j] = infoW[ord2[j]];
	}
	for (int j = 0; j < k; ++ j) {
		for (int u = 1; u <= n; ++ u) {
			cntE ++;
			ord3[cntE] = cntE;
			curU[cntE] = n + j + 1;
			curV[cntE] = u;
			curW[cntE] = valA[j][u];
		}
	}
	if (cntE >= 1) {
		sort(ord3 + 1, ord3 + 1 + cntE, [&](int u, int v) {
			return curW[u] < curW[v];
		});
	}
	
	ll ans = infLL;
	for (int i = 0; i < (1 << k); ++ i) {
		for (int j = 1; j <= n + k; ++ j) {
			dsu[j] = j; nowSiz[j] = 1;
		}
		ll curS = 0;
		int totK = 0;
		for (int j = 0; j < k; ++ j) {
			if ((i >> j) & 1) {
				curS += valC[j];
				totK ++;
			}
		}
		int valO = 0;
		for (int j = 1; j <= cntE; ++ j) {
			if (valO == n + totK - 1) {
				break;
			}
			if (curU[ord3[j]] > n) {
				int pos = curU[ord3[j]] - n - 1;
				if (!(i & (1 << pos))) {
					continue;
				}
			}
			if (LinkE(curU[ord3[j]], curV[ord3[j]])) {
				curS += curW[ord3[j]]; valO ++; 
			}
		}
		ans = min(ans, curS);
	}
	printf("%lld\n", ans);
}

}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	PTqwq::Solve();
	
	return 0;
}
