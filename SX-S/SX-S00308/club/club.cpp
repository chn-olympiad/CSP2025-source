#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+1;
int t, n, a1[N], b1[N], c1[N], maxx;

int dfs(int l, int a, int b, int c, int sum) {
	if (l > n)
		return sum;
	if (a < n / 2)
		maxx = max(maxx, dfs(l + 1, a + 1, b, c, sum + a1[l]));
	if (b < n / 2)
		maxx = max(maxx, dfs(l + 1, a, b + 1, c, sum + b1[l]));
	if (c < n / 2)
		maxx = max(maxx, dfs(l + 1, a, b, c + 1, sum + c1[l]));
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a1[i] >> b1[i] >> c1[i];

		}
		dfs(1, 0, 0, 0, 0);
		cout << maxx << endl;
		maxx = 0;
	}




	return 0;
}
