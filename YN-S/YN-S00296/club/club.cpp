#include <bits/stdc++.h>
#define ll long long
#define db double

int q, n, a1[200001], a2[200001], a3[200001];
int t1, t2, t3, ans;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	scanf("%d", &q);
	while (q--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a1[i], &a2[i], &a3[i]);
		}
		t1 = std::max(a1[1] + a2[2], a1[1] + a3[2]);
		t2 = std::max(a2[1] + a1[2], a2[1] + a3[2]);
		t3 = std::max(a3[1] + a1[2], a3[1] + a2[2]);
		ans = std::max({t1, t2, t3});
		printf("%d", ans);
		puts("");
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}