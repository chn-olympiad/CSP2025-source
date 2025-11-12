#include <iostream>
#include <cstring>
using namespace std;
const int N = 100000 + 5;
int a[N + 5][4], n, a1, a2, a3;

int ans[50] = {0};

void andd (int x[], int y) {
	int cnt = 1;
	while (y) {
		x[cnt] += y % 10;
		x[cnt + 1] += x[cnt ] / 10;
		x[cnt] %= 10;
		y /= 10;
		cnt++;
	}
	return ;
}

void maxx(int x[], int y[]) {
	for (int i = 49; i > 0; i--) {
		if (x[i] > y[i])
			return;
		if (y[i] > x[i])
			break;
	}
	for (int i = 1; i <= 49; i++)
		x[i] = y[i];
}

void dfs(int cnt, int sum[]) {
	if (cnt > n) {
		maxx(ans, sum);
		return;
	}
	int v[50] = {0};
	for (int i = 1; i <= 35; i++) {
		v[i] = sum[i];
	}
	if (a1 < n / 2) {
		a1++;
		andd (v, a[cnt][1]);
		dfs(cnt + 1, v);
		a1--;
	}
	for (int i = 1; i <= 35; i++) {
		v[i] = sum[i];
	}
	if (a2 < n / 2) {
		a2++;
		andd (v, a[cnt][2]);
		dfs(cnt + 1, v);
		a2--;
	}
	for (int i = 1; i <= 35; i++) {
		v[i] = sum[i];
	}
	if (a3 < n / 2) {
		a3++;
		andd (v, a[cnt][3]);
		dfs(cnt + 1, v);
		a3--;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		a1 = 0, a2 = 0, a3 = 0;
		cin >> n;
		memset(a, 0, sizeof(a));
		memset(ans, 0, sizeof(ans));
		for (int j = 1; j <= n; j++) {
			cin >> a[j][1] >> a[j][2] >> a[j][3];
		}
		int f[50] = {0};
		dfs(1, f);
		bool flag = 0;
		for (int i = 49; i > 0; i--) {
			if (ans[i] || flag) {
				cout << ans[i];
				flag = 1;
			}

		}
		cout << endl;
	}
	return 0;
}