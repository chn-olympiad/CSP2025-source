#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t, n, a[N][5];
long long ans = 0;
bool f2, f3;

bool cmp(int x, int y) {
	return x > y;
}

void dfs(int k, int c1, int c2, int c3, long long sum) {
	if (k > n) {
		ans = max(ans, sum);
		return ;
	}
	if (c1 + 1 <= n / 2)
		dfs(k + 1, c1 + 1, c2, c3, sum + a[k][1]);
	if (c2 + 1 <= n / 2)
		dfs(k + 1, c1, c2 + 1, c3, sum + a[k][2]);
	if (c3 + 1 <= n / 2)
		dfs(k + 1, c1, c2, c3 + 1, sum + a[k][3]);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		ans = f2 = f3 = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++)
				cin >> a[i][j];
			if (a[i][2])
				f2 = 1;
			if (a[i][3])
				f3 = 1;
		}
		dfs(1, 0, 0, 0, 0);
		if (!f2 && !f3) {
			int A[N];
			for (int i = 1; i <= n; i++)
				A[i] = a[i][1];
			sort(A + 1, A + n + 1, cmp);
			for (int i = 1; i <= n / 2; i++)
				ans += A[i];
		}
		cout << ans << endl;
	}
	return 0;
}