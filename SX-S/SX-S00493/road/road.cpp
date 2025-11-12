#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int s = 0, r = 1;

struct road {
	int city1;
	int city2;
	int pay;
};
road a[1000005];
int c[10][10005];
int z[2000005];
int ss[10005];

int pd() {
	z[2000005] = {0};
	int x = 1;
	for (int i = 1; i <= m; i++) {
		z[x++] = a[i].city1;
		z[x++] = a[i].city2;
	}
	sort(z + 1, z + 2 * m + 1);
	for (int i = 1; i < x; i++) {
		if ((z[i + 1] - z[i]) >= 2) {
			return 0;
		}
	}
	return 1;
}

void ck(int e, int w) {
	if (e >= n - 1) {
		return ;
	}
	for (int i = w; i <= m; i++) {

		int t1 = a[i].city1, t2 = a[i].city2;
		a[i].city1 = 0;
		a[i].city2 = 0;
		int o = pd();
		if (o == 0) {
			continue;
		} else {
			int s1 = s;
			for (int j = 1; j <= m; j++) {
				if (a[j].city1 == 0) {
					s1 -= a[j].pay;
				}
			}
			ss[r++] = s1;
		}
		ck(e + 1, w += i);
		a[i].city1 = t1;
		a[i].city2 = t2;
	}
	return ;
}

int main() {
//	freopen("road.in", "r", stdin);
//	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> a[i].city1 >> a[i].city2 >> a[i].pay;
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n + 1; j++) {
			cin >> c[i][j];
		}
	}
	for (int i = 1; i <= m; i++) {
		s += a[i].pay;
	}
	int e = 1, w = 1;
	ck(e, w);
	int max = s;
	for (int i = 1; i < r; i++) {
		if (ss[i] < max) {
			max = ss[i];
		}
	}
	cout << max;
	fclose(stdin);
	fclose(stdout);
	return 0;
}