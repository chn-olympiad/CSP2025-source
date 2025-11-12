#include <bits/stdc++.h>
using namespace std;

struct Node {
	int abi, num;
};
Node a[100010], b[100010], c[100010];
int ori[3][100010], u[4][100010], ord[3][100010];

bool cmp(Node x, Node y) {
	return x.abi > y.abi;
}

void solve() {
	memset(u, 0, sizeof u);
	memset(ori, 0, sizeof ori);
	int n;
	cin >> n;
	bool flag = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].abi >> b[i].abi >> c[i].abi;
		if (b[i].abi != 0 || c[i].abi != 0) {
			flag = 0;
		}
		a[i].num = b[i].num = c[i].num = i;
		ori[1][i] = a[i].abi;
		ori[2][i] = b[i].abi;
		ori[3][i] = c[i].abi;
	}
	sort(a + 1, a + 1 + n, cmp);
	sort(b + 1, b + 1 + n, cmp);
	sort(c + 1, c + 1 + n, cmp);
	if (flag) {
		int sum = 0;
		for (int i = 1; i <= n / 2; i++) {
			sum += a[i].abi;
		}
		cout << sum;
		return;
	}
	for (int i = 1; i <= n; i++) {
		ord[1][i] = a[i].num;
		ord[2][i] = b[i].num;
		ord[3][i] = c[i].num;
		if (i > n / 2)
			continue;
		u[1][a[i].num]++;
		u[2][b[i].num]++;
		u[3][c[i].num]++;
		u[4][a[i].num]++;
		u[4][b[i].num]++;
		u[4][c[i].num]++;
	}
	int sum = 0;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= n / 2; j++) {
			sum += ori[i][ord[i][j]];
		}
	}
//	cout << "sum:" << sum << endl;
	for (int i = 1; i <= n; i++) {
		if (u[4][i] > 1) {
			int Max = -1;
			for (int j = 1; j <= 3; j++) {
				if (u[j][i] == 1) {
					int x = n / 2 + 1, alt;
					while (u[4][ord[j][x]] != 0 && x <= n) {
//						cout << ord[j][x] << endl;
						x++;
					}
					if (x > n) {
						alt = 0;
					} else {
//						cout << "***" << endl;
						alt = ori[j][ord[j][x]];
					}
//					cout << '-' << ori[j][i] - alt << ' ' << ori[j][i] << ' ' << alt << endl;
					sum -= (ori[j][i] - alt);
					Max = max(Max, ori[j][i] - alt);
				}
			}
//			cout << '+' << Max << ' ' << i << endl;
			sum += Max;
		}
	}
	cout << sum << endl;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}