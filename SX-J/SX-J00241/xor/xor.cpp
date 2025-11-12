#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+7, M = 1e7+7;
int n, k, a[N], sum[N], cnt;
vector<int> p[M];

struct str {
	int l, r;
} ac[N];

bool cmp(str x, str y) {
	if (x.r != y.r)
		return x.r < y.r;
	return (x.r - x.l) > (y.r - y.l);
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum[i] = sum[i - 1] ^ a[i];
		p[sum[i]].push_back(i);
	}
	for (int i = 0; i < n; i++) {
		if (p[sum[i]^k].size() == 0)
			continue;
		for (int j = 0; j < (int)p[sum[i]^k].size(); j++) {
			if (p[sum[i] ^ k][j] <= i)
				continue;
			ac[++cnt].l = i + 1;
			ac[cnt].r = p[sum[i] ^ k][j];
			break;
		}
	}
	if (cnt == 0)
		printf("0");
	else {
		sort(ac + 1, ac + 1 + cnt, cmp);
		int ans = 1, R = ac[1].r;
		for (int i = 2; i <= cnt; i++) {
			if (ac[i].l <= R)
				continue;
			ans++;
			R = ac[i].r;
		}
		printf("%d", ans);
	}
	return 0;
}