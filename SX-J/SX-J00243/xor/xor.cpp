#include <bits/stdc++.h>
using namespace std;
int n, k, a[500005], s[500005], l[500005], r[500005], cnt;
bool flag[500005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	bool jjfjj = 0;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] > 1)
			jjfjj = 1;
		s[i] = s[i - 1] ^ a[i];
	}
	if (jjfjj) {
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				if ((s[j]^s[i - 1]) == k) {
					cnt++;
					l[cnt] = i, r[cnt] = j;
				}
			}
		}
		int ans = cnt;
		for (int i = 1; i <= cnt; i++) {
			for (int j = i + 1; j <= cnt; j++) {
				if ((l[j] >= l[i] && l[j] <= r[i]) || (r[j] <= r[i] && l[i] <= r[j])) {
					int maxx = 0;
					if (r[j] - l[j] + 1 > r[i] - l[i] + 1)
						maxx = j;
					else
						maxx = i;
					if (!flag[maxx])
						ans--, flag[maxx] = 1;
				}
			}
		}
		cout << ans << endl;
	} else {
		int ans = 0;
		if (k == 0) {
			int lst = 0;
			for (int i = 1; i <= n; i++) {
				if (a[i] == 0) {
					ans++;
					lst = 0;
				} else {
					if (lst) {
						ans++;
						lst = 0;
					} else
						lst = 1;
				}
			}
		}
		if (k == 1) {
			for (int i = 1; i <= n; i++) {
				if (a[i] == 1)
					ans++;
			}
		}
		cout << ans << endl;
	}

	return 0;
}
