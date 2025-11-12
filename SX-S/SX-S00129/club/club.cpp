#include <bits/stdc++.h>
using namespace std;

struct people {
	int a1;
	int a2;
	int a3;
	int maxa;
	int maxn;
} peo[1000005];
int u[1000005], w[1000005];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int N;
	cin >> N;

	while (N--) {
		memset(u, 0, sizeof(u));
		int n, total = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> peo[i].a1 >> peo[i].a2 >> peo[i].a3;
		}
		for (int i = 1; i <= n; i++) {
			if (peo[i].a1 > peo[i].a2) {
				peo[i].maxa = peo[i].a1;
				peo[i].maxn = 1;
			} else {
				peo[i].maxa = peo[i].a2;
				peo[i].maxn = 2;
			}
			if (peo[i].a3 > peo[i].maxa) {
				peo[i].maxa = peo[i].a3;
				peo[i].maxn = 3;
			}
			total += peo[i].maxa;
			u[peo[i].maxn]++;
		}
		bool flag = true;
		int ans, wa = INT_MIN, wn;
		for (int i = 1; i <= 3; i++) {
			if (u[i] > n / 2) {
				flag = false;
				ans = i;
			}
		}
		if (flag) {
			cout << total << endl;
			continue;
		} else {
			for (int i = 1; i <= n; i++) {
				if (peo[i].maxn == ans) {
					if (peo[i].maxn == 1) {
						w[i] = max(peo[i].a2, peo[i].a3);
						if (w[i] > wa) {
							wa = w[i];
							wn = i;
						}
					} else if (peo[i].maxn == 2) {
						w[i] = max(peo[i].a1, peo[i].a3);
						if (w[i] > wa) {
							wa = w[i];
							wn = i;
						}
					} else if (peo[i].maxn == 3) {
						w[i] = max(peo[i].a2, peo[i].a1);
						if (w[i] > wa) {
							wa = w[i];
							wn = i;
						}
					}
				}
			}
		}
		cout << total - peo[wn].maxa + wa << endl;
	}
	return 0;
}
