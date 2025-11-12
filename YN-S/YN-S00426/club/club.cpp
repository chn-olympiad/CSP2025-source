#include <bits/stdc++.h>
using namespace std;
int p[10000000][3];
int n, m;
int l[100000000];

int x1[3] = { 1, 0, 0};

int x2[3] = {0, 1, 0};

int x3[3] = {0, 0, 1};

void dfs(int a, int b, int c, int k,  int min, int u) {
	if (a + b + c == min) {
		l[u] = k;
		u++;
		return;
	}
	for (int i = 0; i < 3; i++) {
		if (x1[i] == 1  ) {
			dfs(a + 1, b, c, k += p[min][0], min++, u);
		} else if (x2[i] == 1 ) {
			dfs(a, b + 1, c, k += p[min][1], min++, u);
		} else {
			dfs(a, b, c + 1, k += p[min][2], min++, u);
		}
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int max = 0;
	int q = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> m;
		max = 0;
		for (int j = 0; j < m; j++) {
			cin >> p[j][0] >> p[j][1] >> p[j][2];
		}
		dfs(0, 0, 0, 0, 0, 1);
		for (int z = 1; z <= 10000000; z++) {
			if (max < l[z])
				max = l[z];
		}
		cout << max << endl;
		for (int x = 0; x < 10000000; x++) {
			p[x][0] = 0;
			p[x][1] = 0;
			p[x][2] = 0;
		}
		max = 0;
		for (int y = 1; y <= 10000000000000; y++) {
			l[y] = 0;
		}
	}
	return 0;
}