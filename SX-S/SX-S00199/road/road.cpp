#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a[10020][10020];
bool vvis[10020][10020];
int b[20];
bool viss[20];
int dis[10020], vis[10020];

int diss[10020];

int qwe(int st) {
	if (diss[st] == -1) {
		return 0;

	} else {
		int l = a[st][diss[st]] * vvis[st][diss[st]];
		vvis[st][diss[st]] = 0;

		if (diss[st] > n) {
			viss[diss[st] - n] = 0;
		}
		int r = b[diss[st] - n] * viss[diss[st] - n];
		return qwe(diss[st]) + l + r;
	}
}

void disj(int st) {
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(dis));
	memset(diss, 0, sizeof(dis));
	dis[st] = 0;
	diss[st] = -1;
	priority_queue< pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > qp;

	qp.push({0, st});

	while (!qp.empty()) {

		auto x = qp.top();
		qp.pop();
		int u = x.second, e = x.first;
		if (vis[u] == 1) {
			continue;
		}
		vis[u] = 1;
		for (int v = 1; v <= n + k; v++) {
			if (v == u) {
				continue;
			}
			int w = a[u][v];
			int ww = 0;
			if (v > n) {
				ww = b[v - n];
			}
			if (dis[u] + w + ww < dis[v]) {
				dis[v] = dis[u] + w + ww;
				qp.push({dis[v], v});
				diss[v] = u;

			}
		}
	}
}



int main() {
	freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	memset(a, 0x3f, sizeof(a));
	for (int i = 1; i <= n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		a[u][v] = w;
		a[v][u] = w;
	}

	for (int i = 1; i <= k; i++) {
		int w;
		cin >> w;
		b[i] = w;
		for (int j = 1; j <= n; j++) {
			int ww;
			cin >> ww;
			a[n + i][j] = ww;
			a[j][n + i] = ww;
		}
	}


	memset(vvis, 1, sizeof(vvis));
	memset(viss, 1, sizeof(viss));
	disj(1);
	long long sum = 0;
//		cout << endl;
	for (int j = 1; j <= n; j++) {
		if (j == 1) {
			continue;
		}
//		sum += dis[i];
		sum += qwe(j);
//			cout << sum << " ";
	}
//		cout << endl;
//		for (int j = 1; j <= n + k; j++) {
//			cout << dis[j] << " ";
//		}
//		cout << endl;
//
//		for (int j = 1; j <= n + k; j++) {
//			cout << diss[j] << " ";
//		}
//		cout << endl << sum << endl;








	cout << sum;
	return 0;
}
