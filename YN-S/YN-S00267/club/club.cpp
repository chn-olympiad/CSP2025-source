#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, saf[N][3], ans, t;
vector<int> q[3];

void dfs(int *l, int res, int num) {
	for (int i = 0; i < 3; i++) {
		if (l[i] > n / 2)
			return;
	}
	if (num == n + 1) {
		ans = max(ans, res);
		return;
	}
	for (int j = 0; j < 3; j++) {
		res += saf[num][j];
		l[j]++;
		num++;
		dfs(l, res, num);
		l[j]--;
		num--;
		res -= saf[num][j];
	}
	return;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < 3; j++)
				scanf("%d", &saf[i][j]);
		ans = 0;
		int l[3] = {};
		dfs(l, 0, 1);
		printf("%d\n", ans);
	}
	return 0;
}