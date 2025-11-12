#include <bits/stdc++.h>
using namespace std;
int ans;
const int MAXN = 1e6+15;
const int MAXM = 1e5+15;
int n, m, k;
bool h, hy;

struct Node {
	int u;
	int v;
	int w;
} a[MAXN];

struct village {
	int c;
	int rd[MAXM];
} v[MAXN];

bool cmp(Node mm, Node nn) {
	return mm.w < nn.w;
}

bool cmp1(village mm, village nn) {
	if (mm.c != nn.c)
		return mm.c < nn.c;
	int Lis = 0, Ls = 0;
	for (int i = 0; i < n; i++) {
		Lis += mm.rd[i];
	}
	for (int i = 0; i < n; i++) {
		Ls += nn.rd[i];
	}
	return Lis < Ls;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	for (int i = 0; i < k; i++) {
		cin >> v[i].c;
		for (int j = 0; j < n; j++) {
			cin >> v[i].rd[j];
			if (v[i].rd[j] != 0 )
				hy = 1;
		}
		if (v[i].c != 0 )
			h = 1;
	}
	if (!h) {
		cout << 0;
	}

	sort(a, a + m, cmp);
	sort(v, v + k, cmp1);

	return 0;
}
