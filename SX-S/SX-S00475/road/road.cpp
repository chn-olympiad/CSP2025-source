#include <bits/stdc++.h>
using namespace std;
const int M = 1e6+10, MM = 1e4+10;
int city, road, town, ans = 0, num[MM];
int con[MM][MM][MM], vis[MM][MM][MM];
int dis_town[20], town_city[20][M], tact[MM][M], vv[MM][MM];
int cnt = 1;

void dfs(int x) {
	vv[cnt][x] = num[cnt];
	for (int i = 1; i <= city; i++) {
		if (vis[cnt][x][i] && !vv[cnt][i]) {
			dfs(i);
		}
	}
}

void dg() {
	for (int i = 1; i <= city; i++) {
		int maax = M;
		for (int j = i + 1; j <= city; j++) {
			if (con[cnt][i][j] && con[cnt][i][j] < maax) {
				maax = con[cnt][i][j];
				tact[cnt][i] = j;
			}
		}
		vis[cnt][i][tact[cnt][i]] = 1;
		vis[cnt][tact[cnt][i]][i] = 1;
		ans += con[cnt][i][tact[cnt][i]];
	}
	for (int i = 1; i <= city; i++) {
		if (vv[cnt][i])
			continue;
		num[cnt]++;
		dfs(i);
	}
	for (int i = 1; i <= city; i++) {
		for (int j = i + 1; j <= city; j++) {
			if (con[cnt][i][j] && !vis[cnt][i][j] && vv[i] != vv[j]) {
				if (!con[cnt + 1][vv[cnt][i]][vv[cnt][j]])
					con[cnt + 1][vv[cnt][i]][vv[cnt][j]] = min(con[cnt + 1][vv[cnt][i]][vv[cnt][j]], con[cnt][i][j]);
				else
					con[cnt + 1][vv[cnt][i]][vv[cnt][j]] = con[cnt][i][j];
			}
		}
	}
	cnt++;
	if (num[cnt] == 1)
		cout << ans;

	else
		dg();
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> city >> road >> town;
	for (int i = 1; i <= road; i++) {
		int from, to, dis;
		cin >> from >> to >> dis ;
		con[cnt][from][to] = dis;
		con[cnt][to][from] = dis;

	}
	for (int i = 1; i <= town; i++) {
		cin >> dis_town[i];
		for (int j = i + 1; j <= city; j++) {
			cin >> town_city[i][j];
		}
	}
	dg();
	return 0;
}
