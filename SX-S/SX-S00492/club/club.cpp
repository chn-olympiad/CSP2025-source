#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e4+10;

int t, cnt, cnt2, tot1, tot2;
ll ans, s1, s2, s3;
int n, arr[N][5], s[5], brr[N];

void dfs(int step) {
	if (step > n) {
		ans = max(ans, s1 + s2 + s3);
		return ;
	}
	if (s[1] < n / 2) {
		s[1]++;
		s1 += arr[step][1];
		dfs(step + 1);
		s1 -= arr[step][1];
		s[1]--;
	}
	if (s[2] < n / 2) {
		s[2]++;
		s2 += arr[step][2];
		dfs(step + 1);
		s2 -= arr[step][2];
		s[2]--;
	}
	if (s[3] < n / 2) {
		s[3]++;
		s3 += arr[step][3];
		dfs(step + 1);
		s3 -= arr[step][3];
		s[3]--;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		s[1] = s[2] = s[3] = s1 = s2 = s3 = ans = cnt = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &arr[i][1], &arr[i][2], &arr[i][3]);
			if (arr[i][2] == 0 && arr[i][3] == 0)
				cnt++;
			if (arr[i][3] == 0)
				cnt2++;
		}
		if (cnt == n) {
			for (int i = 1; i <= n; i++)
				brr[i] = arr[i][1];
			sort(brr + 1, brr + n + 1);
			int c = 0;
			for (int i = n; i; i--) {
				ans += brr[i];
				c++;
				if (c == n / 2)
					break;
			}
			printf("%lld\n", ans);
			memset(brr, 0, sizeof brr);
			continue;
		}
		dfs(1);
		printf("%lld\n", ans);
	}
	return 0;
}
