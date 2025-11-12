#include <bits/stdc++.h>
using namespace std;
long long a[11451];
long long b[11451];
long long c[11451], anss[10];
int cnt = 1;
int kk;
int ji[5];
long long maxx = 0;
long long dp2[201][201];

void dfs(int n, int k, long long h) {
	if (k > n) {
		maxx = max(h, maxx);
		return;
	}
	for (int i = 1; i <= 3; i++) {
		if (ji[i] >= kk)
			continue;
		ji[i]++;
		if (i == 1) {
			dfs(n, k + 1, h + a[k]);
			ji[1]--;
		}
		if (i == 2) {
			dfs(n, k + 1, h + b[k]);
			ji[2]--;
		}
		if (i == 3) {
			dfs(n, k + 1, h + c[k]);
			ji[3]--;
		}
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int v, n;
	cin >> v;
	//cout << "aa";
	while (v--) {
		cin >> n;
		kk = n / 2;
		memset(dp2, 0, sizeof(dp2));
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		memset(ji, 0, sizeof(ji));
		bool jige1 = 0;
		bool jige2 = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
			if (b[i] != 0)
				jige1 = 1;
			if (c[i] != 0)
				jige2 = 1;
		}
		if (jige1 == 0) {
			sort(a + 1, a + n + 1);
			for (int i = 1; i <= kk; i++) {
				maxx += a[n - i + 1];
			}
			anss[cnt++] = maxx;
			goto jige;
		}
		/*if (jige2 == 0) {
			for (int i = 1; i <= n; i++) {
				for (int j = 0; j <= i; j++) {
					if (j > kk)
						continue;
					if (i - j > kk)
						continue;
					dp2[i][j] = max(dp2[i - 1][j] + a[i], dp2[i - 1][j - 1] + b[i]);
					//cout << dp2[i][j] << " ";
				}
				//cout << endl;
			}
			anss[cnt++] = dp2[n][kk];
			goto jige;
		}*/
		if (n <= 31) {
			dfs(n, 1, 0);
			anss[cnt++] = maxx;
			goto jige;
		}

jige:
		;
		maxx = 0;
	}
	for (int i = 1; i < cnt; i++)
		cout << anss[i] << endl;
	return 0;
}
