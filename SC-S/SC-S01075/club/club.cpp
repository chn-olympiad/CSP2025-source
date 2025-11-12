#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int t, n, ans;
int dp[maxn];
int member[maxn];
int group1[maxn], group2[maxn], group3[maxn];

bool cmp(int x, int y) {
	return x > y;
}

int main() {

	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);
		int flag = n / 2;
		int cnt2 = 0, cnt3 = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &group1[i], &group2[i], &group3[i]);
			cnt2 += group2[i];
			cnt3 += group3[i];
		}

		if (cnt2 + cnt3 == 0) {
			sort(group1 + 1, group1 + n + 1, cmp);
			for (int i = 1; i <= flag; i++) ans += group1[i];
		}
		
		printf("%d",ans);
	}

	return 0;
}