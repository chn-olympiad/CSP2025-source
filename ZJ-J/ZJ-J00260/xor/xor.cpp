#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+5, maxm = 3e6+5;
int n, k, a[maxn], pref[maxn], d, ans;
vector<int> v[maxm];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	bool can = true;
	int Max = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] != 1) can = false;
		Max = max(Max, a[i]);
	}
	if (can) {
		ans = (k > 1 ? 0 : (k == 1 ? n : n / 2));
		printf("%d", ans);
		return 0;
	}
	if (Max == 1) {
		if (k > 1) printf("0");
		else {
			int cnt = 0;
			for (int i = 1; i <= n; i++) {
				cnt += a[i];
				if ((cnt == 2 && k == 0) || (cnt == 1 && k == 1)) {
					cnt = 0;
					ans++;
				}
			}
			printf("%d", ans);
		}
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		pref[i] = pref[i - 1] ^ a[i];
		v[pref[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		if (v[k ^ d].size() == 0) {
			d = pref[i];
			continue;
		}
		int l = 0, r = v[k ^ d].size() - 1, j = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (v[k ^ d][mid] >= i) {
				j = mid;
				r = mid - 1;
			} else l = mid + 1;
		}
		if (j == -1) {
			d = pref[i];
			continue;
		}
		ans++;
		i = v[k ^ d][j];
		d = pref[v[k ^ d][j]];
	}
	printf("%d", ans);
	return 0;
}