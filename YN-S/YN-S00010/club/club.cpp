#include <bits/stdc++.h>
using namespace std;
long long t, n, ans;

struct node {
	long long a, b, c;
} a[100005];

void dfs(int x, long long sum, long long a1, long long b, long long c) {
	if (x > n) {
		ans = max(sum, ans);
		return ;
	}
	for (int i = 1; i <= 3; i++) {
		if (i == 1 && a1 >= n / 2 || i == 2 && b >= n / 2 || i == 3 && c >= n / 2)
			continue;
		if (i == 1) {
			dfs(x + 1, sum + a[x].a, a1 + 1, b, c);
		}
		if (i == 2) {
			dfs(x + 1, sum + a[x].b, a1, b + 1, c);
		}
		if (i == 3) {
			dfs(x + 1, sum + a[x].c, a1, b, c + 1);
		}
	}
}

bool cmp(node a, node b) {
	return a.a > b.a;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		memset(a, 0, sizeof(a));
		cin >> n;
		int flag = 1;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].a >> a[i].b >> a[i].c;
			if (a[i].b != 0)
				flag = 0;
		}
		if (flag == 0) {
			sort(a + 1, a + 1 + n, cmp);
			for (int i = 1; i <= n / 2; i++)
				ans += a[i].a;
			cout << ans << endl;
			ans = 0;
			continue;
		}
		dfs(1, 0, 0, 0, 0);
		cout << ans;
		ans = 0;
	}
	return 0;
}