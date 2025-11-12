#include<bits/stdc++.h>
using namespace std;

int t, n, ans;

struct node {
	int a, b, c;
} s[100011];

bool cmp1 (node aaa, node bbb) {
	return aaa.a > bbb.a;
}

void dfs(int t, int sum, int a1, int a2, int a3) {
	if (t == n + 1) {
		ans = max(ans, sum);
		return;
	}
	if (a1 < n / 2)
		dfs (t + 1, sum + s[t].a, a1 + 1, a2, a3);
	if (a2 < n / 2)
		dfs (t + 1, sum + s[t].b, a1, a2 + 1, a3);
	if (a3 < n / 2)
		dfs (t + 1, sum + s[t].c, a1, a2, a3 + 1);
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf ("%d", &t);
	for (int i = 1; i <= t; i++) {
		bool a2 = 1, a3 = 1;
		ans = 0;
		scanf ("%d", &n);
		for (int j = 1; j <= n; j++) {
			scanf ("%d%d%d", &s[j].a, &s[j].b, &s[j].c);
			if (s[j].b != 0)
				a2 = 0;
			if (s[j].c != 0)
				a3 = 0;
		}
		if (a2 == 1 && a3 == 1) {
			sort (s + 1, s + n + 1, cmp1);
			for (int j = 1; j <= n / 2; j++)
				ans += s[j].a;
			printf ("%d\n", ans);
			continue;
		}
		dfs (1, 0, 0, 0, 0);
		printf ("%d\n", ans);
	}
	return 0;
}

