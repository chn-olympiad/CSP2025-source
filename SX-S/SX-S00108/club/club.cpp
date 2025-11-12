#include <bits/stdc++.h>
using namespace std;
int a[100005][4], T, n, v[100005], C[100005], b[4], cnt, ol, ct[100005];
long long ans;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		cnt = 0;
		ans = 0;
		memset(b, 0, sizeof(b));
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
			ans += max(a[i][1], max(a[i][2], a[i][3]));
			int t = min(a[i][1], min(a[i][2], a[i][3]));
			if (t == a[i][3])
				C[i] = max(a[i][1], a[i][2]) - min(a[i][1], a[i][2]);
			else if (t == a[i][2])
				C[i] = max(a[i][1], a[i][3]) - min(a[i][1], a[i][3]);
			else if (t == a[i][1])
				C[i] = max(a[i][2], a[i][3]) - min(a[i][2], a[i][3]);
			int q = max(a[i][1], max(a[i][2], a[i][3]));
			if (q == a[i][3]) {
				v[i] = 3;
				b[3]++;
			} else if (q == a[i][2]) {
				v[i] = 2;
				b[2]++;
			} else if (q == a[i][1]) {
				v[i] = 1;
				b[1]++;
			}
		}
		if (b[1] <= n / 2 && b[2] <= n / 2 && b[3] <= n / 2) {
			printf("%lld\n", ans);
			continue;
		} else if (b[1] > n / 2)
			ol = 1;
		else if (b[2] > n / 2)
			ol = 2;
		else if (b[3] > n / 2)
			ol = 3;
		for (int i = 1; i <= n; i++) {
			if (v[i] == ol) {
				cnt++;
				ct[cnt] = C[i];
			}
		}
		sort(ct + 1, ct + cnt + 1);
//		printf("%d\n", b[ol] - n / 2);
		for (int i = 1; i <= b[ol] - n / 2; i++) {
			ans -= ct[i];
//			printf("%d\n", ct[i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
