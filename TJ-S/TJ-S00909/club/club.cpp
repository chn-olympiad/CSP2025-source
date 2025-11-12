#include <bits/stdc++.h>
using namespace std;
//))()(!^(!&(#
int a[50], b[50][3], maxn = 0;
void dfs(int x, int n) {
	if (x == n) {
		int cnt[3] = {0, 0, 0};
		for (int i = 0; i < n; i++) cnt[a[i]]++;	
		bool flag = 1;
		for (int i = 0; i < 3; i++) if (cnt[i] > n / 2) flag = 0;
		if (flag) {
			int sum = 0;
			for (int i = 0; i < n; i++) sum += b[i][a[i]];
			maxn = max(maxn, sum);
		}
		return ;
	}
	for (int i = 0; i < 3; i++) {
		a[x] = i;
		dfs(x + 1, n);
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> b[i][0] >> b[i][1] >> b[i][2];
		maxn = 0;
		dfs(0, n);
		cout << maxn << endl;
	}
	return 0;
}
