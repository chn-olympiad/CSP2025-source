#include <bits/stdc++.h>
using namespace std;
int t, n, maxx, s1, s2, s3, m;
int a[10005][5];

void dfs(int i, int love) {
	if (s1 > m || s2 > m || s3 > m)
		return;
	if (i > n && s1 <= m && s2 <= m && s3 <= m) {
		maxx = max(maxx, love);
		return;
	}
	if (n < 200) {
		s1++;
		dfs(i + 1, love + a[i][1]);
		s1--;
		s2++;
		dfs(i + 1, love + a[i][2]);
		s2--;
		s3++;
		dfs(i + 1, love + a[i][3]);
		s3--;
	} else {
		s1++;
		dfs(i + 1, love + a[i][1]);
		s1--;
		s2++;
		dfs(i + 1, love + a[i][2]);
		s2--;
	}
	return;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		m = n / 2, maxx = 0, s1 = 0, s2 = 0, s3 = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= 3; j++)
				cin >> a[i][j];
		dfs(1, 0);
		cout << maxx << endl;
	}
	return 0;
}