// 晴空万里予花绽
// Think twice, code once.
#include <queue>
#include <tuple>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#define eputchar(c) putc(c, stderr)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define eputs(str) fputs(str, stderr), putc('\n', stderr)
using namespace std;

int T, n, a[100005][3];
priority_queue<int> q[3];
long long ans;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
		for (int i = 0; i < 3; i++)
			while (!q[i].empty()) q[i].pop();
		int siz[3] = {0, 0, 0};
		ans = 0;
		for (int i = 1; i <= n; i++) {
			int ans = -1, step;
			auto chmax = [&ans, &step](int res, int to) -> void {
				if (res > ans) ans = res, step = to;
				return;
			};
			for (int j = 0; j < 3; j++)
				if (siz[j] < n / 2) chmax(a[i][j], j);
				else chmax(a[i][j] + q[j].top(), j);
			::ans += ans;
			if (siz[step] < n / 2) {
				int val = ~0x3f3f3f3f;
				for (int j = 0; j < 3; j++)
					if (j != step) val = max(val, a[i][j] - a[i][step]);
				q[step].push(val);
				siz[step]++;
			} else {
				q[step].pop();
				int val = ~0x3f3f3f3f;
				for (int j = 0; j < 3; j++)
					if (j != step) val = max(val, a[i][j] - a[i][step]);
				q[step].push(val);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}