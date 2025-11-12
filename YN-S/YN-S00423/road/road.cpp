#include <bits/stdc++.h>
using namespace std;
int n, m, k;
const int N = 1e5 + 5;
int w[N], v[N], u[N];
int a[10001][10001], num;
int hege, tmp;

void dfs(int i1, int j1) {
	if (i1 == 0 && j1 == 0)
		return ;

	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= m; j++) {

			if (hege < a[i][j]) {
				hege = a[i][j];
			}
		}
	}

	for (int o = tmp; o <= hege; o) {

		tmp += hege;

		for (int i = 1; i <= k; i++) {

			if (min(w[i], v[i]) && tmp) {
				dfs(i + 1, k - i);
			} else {
				hege = w[i] - v[i] + min(hege, tmp);
			}
		}
	}
}

int main() {

	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= m; j++) {


			dfs(i, j);
		}
	}

	for (int i = 1; i <= k; i++) {

		cout << hege;
	}

	return 0;
}