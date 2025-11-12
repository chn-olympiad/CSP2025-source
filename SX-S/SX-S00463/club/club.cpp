#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct mem {
	int n;
	int nf;
	int nn;
} sth[4];

bool cmp(mem aa, mem bb) {
	return aa.n > bb.n;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		int members;
		cin >> members;
		int a[members + 1][4];
		string a1[4];
		sth[1].nn = 1;
		sth[2].nn = 2;
		sth[3].nn = 3;
		for (int i = 1; i <= members; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		for (int i = 1; i <= members; i++) {
			if (a[i][1] == max(a[i][1], max(a[i][2], a[i][3]))) {
				sth[1].n += 1;
				sth[1].nf += a[i][1];
				a1[1][i] = i - '0';
				a1[2][i] = 0;
				a1[3][i] = 0;
			} else if (a[i][2] == max(a[i][2], max(a[i][1], a[i][3]))) {
				sth[2].n += 1;
				sth[2].nf += a[i][2];
				a1[1][i] = 0;
				a1[2][i] = i - '0';
				a1[3][i] = 0;
			} else {
				sth[3].n += 1;
				sth[3].nf += a[i][3];
				a1[1][i] = 0;
				a1[2][i] = 0;
				a1[3][i] = i - '0';
			}
		}
		if ((sth[1].n <= members / 2 && sth[2].n <= members / 2) && sth[3].n <= members / 2) {
			cout << sth[1].nf + sth[2].nf + sth[3].nf << endl;
			continue;
		}
		sort(sth + 1, sth + 4, cmp);
		for (int i = 1; i <= 2; i++) {
			bool vis[members + 1];
			for (int j = 1; j <= members; j++) {
				if (a1[sth[i].nn][j] == j) {
					vis[j] = 1;
				} else
					vis[j] = 0;
			}
			if (sth[i].n <= members / 2) {
				continue;
			}
			int x[100000], dp = 21474;
			for (int j = 1; j <= members; j++) {
				if (vis[j] == 1 && a[j][sth[i].nn] <= dp) {
					for (int k = members; k >= 1; k--) {
						x[k] = x[k - 1];
					}
					x[0] = j;
					dp = a[j][sth[i].nn];
				}
			}
			for (int j = 0; j < sth[i].n - members / 2; j++) {
				sth[i].nf -= a[x[j]][sth[i].nn];
			}
			if (i == 1) {
				for (int j = 0; j < sth[i].n - members / 2; j++) {
					if (a[x[j]][sth[2].nn] > a[x[j]][sth[3].nn]) {
						sth[2].nf += a[x[j]][2];
						a1[sth[1].nn][i] = 0;
						a1[sth[2].nn][i] = i - '0';
						a1[sth[3].nn][i] = 0;
					} else {
						sth[3].nf += a[x[j]][3];
						a1[sth[2].nn][i] = 0;
					}
				}
			}
			if (i == 2) {
				for (int j = 0; j < sth[i].n - members / 2; j++) {
					sth[3].nf += a[x[j]][3];
				}
			}
		}
		cout << sth[1].nf + sth[2].nf + sth[3].nf << endl;
	}
	return 0;
}