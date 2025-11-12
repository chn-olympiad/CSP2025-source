#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, M = 1e4 + 5;
long long n, m, k, cnt, dzeko[M][M], ld;
bool yes[M][M], mos[15][M];

struct node {
	long long a, b, v;
} city[N];

struct edge {
	long long ex, id;
	long long val[N + 1];
	bool mor;
} town[15];

bool cmp1(node a, node b) {
	return a.v < b.v;
}

bool cmp2(edge a, edge b) {
	return a.ex < b.ex;
}

int main() {
//	freopen("road.in", "r", stdin);
//	freopen("road.out", "w", stdout);
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	scanf("%d%d%d", n, m, k);
	for (long long i = 1; i <= m; ++i) {
		cin >> city[i].a >> city[i].b >> city[i].v;
	}
	for (long long i = 1; i <= k; ++i) {
		cin >> town[i].ex;
		for (long long j = 2; j <= n + 1; ++j) {
			cin >> town[i].val[j];
		}
		town[i].id = i;
	}
	sort(city + 1, city + m + 1, cmp1);
	sort(town + 1, town + m + 1, cmp2);
	for (long long i = 1; i <= n; ++i) {
		yes[i][i] = 1;
	}
	for (long long i = 1; i <= m; ++i) {
		if (yes[city[i].a][city[i].b] == 0) {
			long long uvw = town[i].val[city[i].a] + town[i].val[city[i].b] + town[i].ex;
			long long uv = town[i].val[city[i].a] + town[i].val[city[i].b];
			if (uvw < city[i].v) {
				if (town[i].mor == 0) {
					if (uvw < city[i].v) {
						cnt += uvw;
						yes[city[i].a][city[i].b] = 1;
						mos[city[i].b][town[i].id] = 1;
						mos[city[i].a][town[i].id] = 1;
					} else {
						cnt += city[i].v;
						yes[city[i].a][city[i].b] = 1;
					}
				} else {
					if (uv < city[i].v) {
						cnt += uv;
						yes[city[i].a][city[i].b] = 1;
						mos[city[i].b][town[i].id] = 1;
						mos[city[i].a][town[i].id] = 1;
						for (long long j = 1; j <= n; ++j) {
							if (mos[town[i].id][j] = 1) {
								yes[city[i].a][j] = 1;
								yes[city[i].b][j] = 1;
							}
						}
					} else {
						cnt += city[i].v;
						yes[city[i].a][city[i].b] = 1;
					}
				}
			}
		}

	}
	cout << cnt;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}