#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int t, n, ans, cnt = 1, h[N];
int a[N][5], g[4], p[4];

int c[10][4] = {{0, 0, 0, 0}, {0, 1, 2, 3}, {0, 1, 3, 2}, {0, 2, 1, 3}, {0, 2, 3, 1}, {0, 3, 1, 2}, {0, 3, 2, 1}};

struct node {
	int x, d;
	bool operator<(const node &t)const {
		return d > t.d;
	}
};
bool b[N];

struct ss {
	int x, y, z, maxx;
	bool operator<(const ss &t)const {
		return maxx < t.maxx;
	}
} s[N];

void dfs(int x, int tot) {
	if (x > n) {
		ans = max(ans, tot);
		return ;
	}

	for (int i = 1; i <= 3; i++) {

		if (g[i] < n / 2) {
			tot += a[x][i];
			g[i]++;
			dfs(x + 1, tot);
			g[i]--;
			tot -= a[x][i];
		}
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);

	while (t--) {
		priority_queue<node> q;
		ans = 0;
		scanf("%d", &n);

		if (n <= 18) {

			for (int i = 1; i <= n; i++) {

				scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
			}

			dfs(1, 0);
			printf("%d\n", ans);
			continue;
		}

		memset(b, 0, sizeof b);

		for (int i = 1; i <= n; i++) {

			scanf("%d%d%d", &s[i].x, &s[i].y, &s[i].z);
			s[i].maxx = max(s[i].x, max(s[i].y, s[i].z));
		}

		sort(s + 1, s + n + 1);

		for (int i = 1; i <= n; i++) {

			a[i][1] = s[i].x;
			a[i][2] = s[i].y;
			a[i][3] = s[i].z;
		}

		for (int k = 1; k <= 6; k++) {

			int tot = 0;
			memset(b, 0, sizeof b);
			memset(h, 0, sizeof h);

			for (int j = 1; j <= 3; j++) {

				int  m = c[k][j];
				p[m] = 0;

				for (int i = 1; i <= n; i++) {

					if (p[m] < n / 2 && b[i]) {
						if (a[i][m] > a[i][h[i]]) {
							tot += a[i][m] - a[i][h[i]];
							ans = max(ans, tot);
							q.push(node{i, a[i][m]});
							p[h[i]]--;
							h[i] = m;
							p[m]++;
						}
					}
				}

				for (int i = 1; i <= n; i++) {

					if (p[m] < n / 2 && !b[i]) {
						tot += a[i][m];
						ans = max(ans, tot);
						q.push(node{i, a[i][m]});
						h[i] = m;
						b[i] = 1;
						p[m]++;
					} else if (p[m] >= n / 2 && !b[i]) {
						if (a[i][m] > q.top().d) {
							tot += a[i][m] - q.top().d;
							ans = max(ans, tot);
							b[q.top().x] = 0;
							h[q.top().x] = 0;
							h[i] = m;
							b[i] = 1;
							q.pop();
							q.push(node{i, a[i][m]});
						}
					}

				}

				while (!q.empty())
					q.pop();

			}

			for (int j = 1; j <= 3; j++) {

				int  m = c[k][j];

				for (int i = 1; i <= n; i++) {

					if (p[m] < n / 2 && b[i]) {
						if (a[i][m] > a[i][h[i]]) {
							tot += a[i][m] - a[i][h[i]];
							ans = max(ans, tot);
							q.push(node{i, a[i][m]});
							p[h[i]]--;
							h[i] = m;
							p[m]++;
						}
					}
				}

				for (int i = 1; i <= n; i++) {

					if (p[m] < n / 2 && !b[i]) {
						tot += a[i][m];
						ans = max(ans, tot);
						q.push(node{i, a[i][m]});
						h[i] = m;
						b[i] = 1;
						p[m]++;
					} else if (p[m] >= n / 2 && !b[i]) {
						if (a[i][m] > q.top().d) {
							tot += a[i][m] - q.top().d;
							ans = max(ans, tot);
							b[q.top().x] = 0;
							h[q.top().x] = 0;
							h[i] = m;
							b[i] = 1;
							q.pop();
							q.push(node{i, a[i][m]});
						}
					}

				}

				while (!q.empty())
					q.pop();

			}

			ans = max(ans, tot);
		}

		printf("%d\n", ans);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}