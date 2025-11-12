#include <bits/stdc++.h>
using namespace std;
int ba[10001];
int kkk[11][10001];

struct node {
	int go, to, w;
} a[1145140];

bool cmp(node a1, node a2) {
	return a1.w < a2.w;
}

int found(int n) {
	if (ba[n] == n)
		return n;
	else {
		ba[n] = found(ba[n]);
		return ba[n];
	}
}

//priority_queue<int>
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k, cnt = m + 1;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> a[i].go >> a[i].to >> a[i].w;
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= m; j++) {
			cin >> kkk[i][j];
		}
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k1 = j; k1 <= n; k1++) {
				a[cnt].go = j;
				a[cnt].to = k1;
				a[cnt++].w = kkk[i][0] + kkk[i][j] + kkk[i][k1];
			}
		}
	}
	//sort(a + 1, a + m + 1 + cnt, cmp);
	for (int i = 1; i < n ; i++) {

		ba[i] = i;
	}
	long long anss = 0;
	if (k == 0) {
		sort(a + 1, a + m + 1, cmp);
		for (int i = 1; i <= m; i++) {
			ba[a[i].to] = a[i].go;
			for (int j = 1; j <= n; j++)
				ba[j] = found(j);
			anss += a[i].w;
			for (int j = 1; j < n; j++) {
				if (ba[j] != ba[j + 1])
					goto jige;
			}
			cout << anss;
			break;
jige:
			;
		}
	}
	return 0;
}
