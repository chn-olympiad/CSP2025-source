#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e5 + 10;
const int M = 210;

int T, n;
bool flagA, flagB;
int ans;
int st[N];
int f[M][M / 2][M / 2];
int value[N][4];
int a[N];


void dfs(int u, int x, int y, int z, int sum) {
	if (u == n + 1) {
		ans = max(ans, sum);
		return;
	}
	if (x < n / 2)
		dfs(u + 1, x + 1, y, z, sum + value[u][1]);
	if (y < n / 2)
		dfs(u + 1, x, y + 1, z, sum + value[u][2]);
	if (z < n / 2)
		dfs(u + 1, x, y, z + 1, sum + value[u][3]);
	return;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		flagA = 1, flagB = 1;
		for (int i = 1; i <= n; i++) {
			cin >> value[i][1] >> value[i][2] >> value[i][3];
			if (value[i][2] || value[i][3])
				flagA = 0;
			if (value[i][3])
				flagB = 0;
		}
		ans = 0;
		if (n <= 10) {
			dfs(1, 0, 0, 0, 0);
			cout << ans << '\n';
		} else if (flagA) {
			for (int i = 1; i <= n; i++)
				a[i] = value[i][1];
			sort(a + 1, a + 1 + n);
			for (int i = 1; i <= n / 2; i++)
				ans += a[i];
			cout << ans << '\n';
		} else if (n <= 200) {
			memset(f, 0, sizeof(f));
			for (int i = 1; i <= n; i++) {
				for (int j = 0; j <= n / 2; j++) {
					for (int k = 0; k <= n / 2; k++) {
						int x = i - j - k;
						if (x < 0 || x > n / 2) {
							continue;
						}
						if (j > 0)
							f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][k] + value[i][1]);
						if (k > 0)
							f[i][j][k] = max(f[i][j][k], f[i - 1][j][k - 1] + value[i][2]);
						if (x > 0)
							f[i][j][k] = max(f[i][j][k], f[i - 1][j][k] + value[i][3]);
//						if (f[i][j][k] == f[i - 1][j - 1][k] + value[i][1])
//							cout << "1 " << i << ' ' << j << ' ' << k << ' ' << f[i][j][k] << endl;
//						if (f[i][j][k] == f[i - 1][j ][k - 1] + value[i][2])
//							cout << "2 " << i << ' ' << j << ' ' << k << ' ' << f[i][j][k] << endl;
//						if (f[i][j][k] == f[i - 1][j ][k] + value[i][3])
//							cout << "3 " << i << ' ' << j << ' ' << k << ' ' << f[i][j][k] << endl;
					}
				}
			}
			ans = 0;
			for (int i = 1; i <= n / 2; i++)
				for (int j = 1; j <= n / 2; j++)
					ans = max(ans, f[n][i][j]);
			cout << ans << '\n';
		}
	}
	return 0;
}