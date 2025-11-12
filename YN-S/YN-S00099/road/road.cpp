#include <bits/stdc++.h>
using namespace std;

int n, m, k, x, y, cnt, a, b;

int ma[10010][10010];


bool ff[10010], tem;

struct edge {
	int fm;
	int to;
	int bl;
} ed[20010];

struct str {
	int mo;
	int dt[10010];
} cot[20];

int cd(int f, int t) {
	int s = 0;
	for (int i = 1; i <= k; i++) {
		if (i == 1)
			s = cot[i].mo + cot[i].dt[f] + cot[i].dt[t];
		else
			s = min(s, cot[i].mo + cot[i].dt[f] + cot[i].dt[t]);
	}
	return s;
}

bool cmp(edge s1, edge s2) {
	if (s1.bl < s2.bl )
		return true;
	return false;
}

void cl() {
	for (int i = 2; i <= n; i++) {
		if (ma[1][i] == 1) {
			for (int j = 1; j <= n; j++) {
				if (ma[i][j] == 1)
					ma[1][j] = 1;
			}
		}
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		cin >> ma[x][y];
		ma[y][x] = ma[x][y];
	}
	for (int i = 1; i <= k; i++) {
		cin >> cot[i].mo ;
		for (int j = 1; j <= n; j++) {
			cin >> cot[i].dt[j];
		}
	}
	x = 0;
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			ed[++x].fm = i;
			ed[x].to = j;
			y = cd(i, j);

			if (ma[i][j] > 0) {
				ed[x].bl  = min(ma[i][j], y);
			} else {
				ed[x].bl = y;
			}
			//cout << i << ' ' << j << ' ' << ma[i][j] << ' ' << y  << ed[x].bl << endl;
		}
	}
	sort(ed + 1, ed + x + 1, cmp);
	memset(ma, 0, sizeof(ma));
	for (int i = 1; i <= x; i++) {
		a = ed[i].fm;
		b = ed[i].to;

		//cout << a << ' ' << b << ' ' <<  ed[i].bl << endl;
		if (!ff[a] || !ff[b]) {
			cnt += ed[i].bl;
			ma[a][b] = 1;
			ma[b][a] = 1;
		}
		if (i >= x / 2) {
			cl();
			tem = false;
			for (int i = 1; i <= n; i++) {
				if (ma[1][i] != 1) {
					tem = true;
					break;
				}
			}
			if (!tem)
				break;
		}
	}
	cout << cnt;
	return 0;
}