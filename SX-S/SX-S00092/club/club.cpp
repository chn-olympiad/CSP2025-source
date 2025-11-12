#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int n, t, num1, num2, num3, ans, num;

struct node {
	int a, b, c, ind;
	int front, last;
} a[maxn];

void dfs(int u) {
	if (u == n) {
		if (num1 < n / 2)
			ans = max(ans, num + a[u].a);
		if (num2 < n / 2)
			ans = max(ans, num + a[u].b);
		if (num3 < n / 2)
			ans = max(ans, num + a[u].c);
		return;
	}
	if (num1 < n / 2) {
		num += a[u].a;
		num1++;
		dfs(u + 1);
		num -= a[u].a;
		num1--;
	}
	if (num2 < n / 2) {
		num2++;
		num += a[u].b;
		dfs(u + 1);
		num -= a[u].b;
		num2--;
	}
	if (num3 < n / 2) {
		num += a[u].c;
		num3++;
		dfs(u + 1);
		num3--;
		num -= a[u].c;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		ans = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].c);
		}
		dfs(1);
		cout << ans << endl;
	}
	return 0;
}
