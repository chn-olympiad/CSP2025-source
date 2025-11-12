#include <bits/stdc++.h>
using namespace std;
int ns1[100005], ns2[100005], ns3[100005];
int n, t;
int ans = -0x3f;

int qzh[5][100005] = {0};

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", n);
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &ns1[i], &ns2[i], &ns3[i]);
		}
		sort(ns1 + 1, ns1 + n + 1);
		sort(ns2 + 1, ns2 + n + 1);
		sort(ns3 + 1, ns3 + n + 1);
		for (int i = 1; i <= 3; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == 1)
					qzh[i][j] = qzh[i][j - 1] + ns1[j];
				if (i == 2)
					qzh[i][j] = qzh[i][j - 1] + ns2[j];
				if (i == 3)
					qzh[i][j] = qzh[i][j - 1] + ns3[j];
			}
		}
		int m[3] = {0};
		for (int i = 1; i <= 3; i++) {
			for (int j = 1; j <= n / 2; j++) {
				m[i] = max(qzh[i][j + n / 2] - qzh[i][j], m[i]);
			}
		}
		ans = m[1] + m[2] + m[3];
		printf("%d", ans);
	}
	return 0;
}