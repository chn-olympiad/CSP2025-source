#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int a[N][3], b[4], c[N];
int n, t;
long long ans = 0;
bool teA = true, teB = true;

bool cmpA(int u, int v) {
	return u > v; 
}

void dfs(int now, long long res) {
	if (now > n) {
		if (res > ans) {
			ans = res;
		}
		return;
	}
	if (b[1] < n / 2 && !(b[2] < b[1] && a[now][1] > a[now][0]) || (b[3] < b[1] && a[now][2] > a[now][0])) {
		b[1]++;
		dfs(now + 1, res + a[now][0]);
		b[1]--;
	}
	if (b[2] < n / 2 && !(b[1] < b[2] && a[now][0] > a[now][1]) || (b[3] < b[2] && a[now][2] > a[now][1])) {
		b[2]++;
		dfs(now + 1, res + a[now][1]);
		b[2]--;
	}
	if (!teB && b[3] < n / 2 && !(b[2] < b[3] && a[now][1] > a[now][2]) || (b[1] < b[3] && a[now][0] > a[now][2])) {
		b[3]++;
		dfs(now + 1, res + a[now][2]);
		b[3]--;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	scanf("%d", &t);
	while (t--) {
		ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
			c[i] = a[i][0];
			if (a[i][1] != 0 || a[i][2] != 0) {
				teA = false;
			}
			if (a[i][2] != 0) {
				teB = false;
			}
		}
		if (teA) {
			sort(c + 1, c + 1 + n, cmpA);
			for (int i = 1; i <= n / 2; i++) {
				ans += c[i];
			}
			printf("%lld\n", ans);
		} else {
			dfs(1, 0);
			printf("%lld\n", ans);
		}
	}
	return 0;
}
