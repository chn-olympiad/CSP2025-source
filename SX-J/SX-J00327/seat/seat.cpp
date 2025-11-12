#include <bits/stdc++.h>
using namespace std;
const int N = 1e2+5;
int n, m, a[N], num, sum, dis[15][15], k = 0;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m >> a[1];
	num = n * m, sum = a[1];
	for (int i = 2; i <= num; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + num, cmp);
	bool flag = 0;
	for (int i = 1; i <= m; i++) {
		if (flag == 0) {
			for (int j = 1; j <= n; j++) {
				dis[j][i] = a[++k];
			}
			flag = 1;
		} else {
			for (int j = n; j >= 1; j--) {
				dis[j][i] = a[++k];
			}
			flag = 0;
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (dis[j][i] == sum) {
				cout << i << " " << j;
				return 0;
			}
		}
	}
	return 0;
}