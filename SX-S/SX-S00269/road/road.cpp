#include <bits/stdc++.h>
using namespace std;
long long n, m, k, u[1000005], v[1000005], w[1000005], c[15], a[15][10005], d[15], maxs, s;

struct ww {
	long long sz, fy, wz;
} b[10005];

//int csp(int a1, int b1) {
//	long long minx = INT_MAX;
//	for (int i = 1; i <= m; i++) {
//		if (u[i] == a1 && v[i] != b1 && b[v[i]].wz == a1) {
//			minx = 0;
//			return 0;
//		}
//		if (u[i] == a1 && v[i] != b1 && b[v[i]].wz != a1) {
//			minx = min(minx, w[i]);
//		}
//		if (u[i] == b1 && v[i] != a1 && b[v[i]].wz != b1) {
//			minx = min(minx, w[i]);
//		}
//		if (u[i] == b1 && v[i] != a1 && b[v[i]].wz == b1) {
//			minx = 0;
//			return 0;
//		}
//		if (v[i] == a1 && u[i] != b1 && b[u[i]].wz == a1) {
//			minx = 0;
//			return 0;
//		}
//		if (v[i] == a1 && u[i] != b1 && b[u[i]].wz != a1) {
//			minx = min(minx, w[i]);
//		}
//		if (v[i] == b1 && u[i] != a1 && b[u[i]].wz != b1) {
//			minx = min(minx, w[i]);
//		}
//		if (v[i] == b1 && u[i] != a1 && b[u[i]].wz == b1) {
//			minx = 0;
//			return 0;
//		}
//	}
//	for (int i = 1; i <= k; i++) {
//		if (d[i] == 0) {
//			if (minx > a[i][a1] + c[i] && b[a1].wz != s + i) {
//				minx = a[i][a1] + c[i];
//				d[i] = 1;
//			}
//		} else {
//			if (minx > a[i][a1] && b[a1].wz != s + i)
//				minx = a[i][a1];
//		}
//		if (d[i] == 0) {
//			if (minx > a[i][b1] + c[i] && b[b1].wz != s + i) {
//				minx = a[i][b1] + c[i];
//				d[i] = 1;
//			}
//		} else {
//			if (minx > a[i][b1] && b[b1].wz != s + i)
//				minx = a[i][b1];
//		}
//	}
//	return minx;
//}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	s = max(n, m);
	for (int i = 1; i <= n; i++) {
		b[i].fy = INT_MAX;
	}

	for (int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i] >> w[i];
		if (b[u[i]].fy > w[i]) {
			b[u[i]].fy = w[i];
//			b[u[i]].wz = v[i];
		}
		if (b[v[i]].fy > w[i]) {
			b[v[i]].fy = w[i];
//			b[v[i]].wz = u[i];
		}
	}

	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		d[i] = 0;
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if (d[i] == 0) {
				if (b[j].fy > a[i][j] + c[i]) {
					b[j].fy = a[i][j] + c[i];
//					b[j].wz = s + i;
					d[i] = 1;
				}
			} else {
				if (b[j].fy > a[i][j])
//					b[j].wz = s + i;
					b[j].fy = a[i][j];
			}
		}

//		for (int i = 1; i <= n; i++) {
//			cout << b[i].fy << " ";
////		maxs += b[i].fy;
//		}
//		cout << endl;
	}

	for (int i = 1; i <= n; i++) {
//		cout << b[i].fy << " ";
//		if (i == b[b[i].wz].wz && b[b[i].wz].wz > i) {
//			maxs += min(b[i].fy, b[b[i].wz].fy);
//			maxs += csp(i, b[b[i].wz].wz);
//		} else
		maxs += b[i].fy;
	}
	cout << maxs;
	return 0;
}