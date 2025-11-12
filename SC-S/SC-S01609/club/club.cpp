#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 5;

int T;
int n;
int ans;
int vis[5];

struct node {
	int cnt0, cnt1, cnt2;
	int cha;
} a[N];

bool cmp(node x, node y) {
	return x.cha > y.cha;
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%lld", &T);
	while (T--) {
		ans = 0;
		scanf("%lld", &n);
		vis[0] = vis[1] = vis[2] = 0;
		ans = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d%d%d", &a[i].cnt0, &a[i].cnt1, &a[i].cnt2);
			int maxn1 = max(a[i].cnt0, max(a[i].cnt1, a[i].cnt2)), maxn2;
			if (maxn1 == a[i].cnt0) {
				maxn2 = max(a[i].cnt1, a[i].cnt2);
			} else if (maxn1 == a[i].cnt1) {
				maxn2 = max(a[i].cnt0, a[i].cnt2);
			} else if (maxn1 == a[i].cnt2) {
				maxn2 = max(a[i].cnt1, a[i].cnt0);
			}
			a[i].cha = maxn1 - maxn2;
		}
		sort(a + 1, a + 1 + n, cmp);
		for (int i = 1; i <= n; ++i) {
			int maxn1 = max(a[i].cnt0, max(a[i].cnt1, a[i].cnt2)), max1id;
			bool vis0 = 0, vis1 = 0, vis2 = 0;
			int maxn2, max2id;
			if (maxn1 == a[i].cnt0) {
				maxn2 = max(a[i].cnt1, a[i].cnt2);
				vis0 = 1;
				max1id = 0;
			} else if (maxn1 == a[i].cnt1) {
				maxn2 = max(a[i].cnt0, a[i].cnt2);
				vis1 = 1;
				max1id = 1;
			} else if (maxn1 == a[i].cnt2) {
				maxn2 = max(a[i].cnt1, a[i].cnt0);
				vis2 = 1;
				max1id = 2;
			}
			if (vis[max1id] + 1 <= n / 2) {
				vis[max1id] += 1;
				if (max1id == 0) {
					ans += a[i].cnt0;
				} else if (max1id == 1) {
					ans += a[i].cnt1;
				} else if (max1id == 2) {
					ans += a[i].cnt2;
				}
				continue;
			}

			int maxn3 = min(min(a[i].cnt0, a[i].cnt1), a[i].cnt2), max3id;
			if (maxn2 == a[i].cnt0) {
				if (!vis0) {
					max2id = 0;
					vis0 = 1;
				}
			}
			if (maxn2 == a[i].cnt1) {
				if (!vis1) {
					max2id = 1;
					vis1 = 1;
				}
			}
			if (maxn2 == a[i].cnt2) {
				if (!vis2) {
					max2id = 2;
					vis2 = 1;
				}
			}
			if (vis[max2id] + 1 <= n / 2) {
				vis[max2id] += 1;
				if (max2id == 0) {
					ans += a[i].cnt0;
				} else if (max2id == 1) {
					ans += a[i].cnt1;
				} else if (max2id == 2) {
					ans += a[i].cnt2;
				}
				continue;
			}
			
			if (maxn3 == a[i].cnt0) {
				if (!vis0) {
					max3id = 0;
					vis0 = 1;
				}
			}
			if (maxn3 == a[i].cnt1) {
				if (!vis1) {
					max3id = 1;
					vis1 = 1;
				}
			}
			if (maxn3 == a[i].cnt2) {
				if (!vis2) {
					max3id = 2;
					vis2 = 1;
				}
			}
			if (vis[max3id] + 1 <= n / 2) {
				vis[max3id] += 1;
				if (max3id == 0) {
					ans += a[i].cnt0;
				} else if (max3id == 1) {
					ans += a[i].cnt1;
				} else if (max3id == 2) {
					ans += a[i].cnt2;
				}
				continue;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}