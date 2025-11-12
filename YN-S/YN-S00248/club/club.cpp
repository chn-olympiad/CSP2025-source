#include <bits/stdc++.h>
#define val first
#define idx second
using namespace std;

int T, n, choose[100005], cnt[3] = {0, 0, 0};

struct node {
	pair<int, int> x, y, z;
} a[100005];

bool cmp1(const node &n1, const node &n2) {
	return n1.x.val > n2.x.val;
}

bool cmp2(const node &n1, const node &n2) {
	return n1.y.val > n2.y.val;
}

bool cmp3(const node &n1, const node &n2) {
	return n1.z.val > n2.z.val;
}

int dfs(int curr, int ret) {
	if (curr == n + 1)
		return ret;
	int ans = 0;
	if (cnt[0] < n / 2) {
		cnt[0] += 1;
		ans = max(dfs(curr + 1, ret + a[curr].x.val), ans);
		cnt[0] -= 1;
	}
	if (cnt[1] < n / 2) {
		cnt[1] += 1;
		ans = max(dfs(curr + 1, ret + a[curr].y.val), ans);
		cnt[1] -= 1;
	}
	if (cnt[2] < n / 2) {
		cnt[2] += 1;
		ans = max(dfs(curr + 1, ret + a[curr].z.val), ans);
		cnt[2] -= 1;
	}
	return ans;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cout.tie(nullptr), cin.tie(nullptr);
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i].x.val >> a[i].y.val >> a[i].z.val;
			a[i].x.idx = 0;
			a[i].y.idx = 1;
			a[i].z.idx = 2;
			choose[i] = 0;
		}
		memset(cnt, 0, sizeof(cnt));
		int ans = 0;
		if (n <= 20) {
			cout << dfs(1, 0) << '\n';
			continue;
		}
		for (int i = 1; i <= n; ++i) {
			if (a[i].y.val > a[i].x.val)
				swap(a[i].y, a[i].x);
			if (a[i].z.val > a[i].x.val)
				swap(a[i].z, a[i].x);
			if (a[i].z.val > a[i].y.val)
				swap(a[i].z, a[i].y);
		}
		sort(a + 1, a + n + 1, cmp1);
		for (int i = 1; i <= n; ++i) {
			if (cnt[a[i].x.idx] < n / 2) {
				ans += a[i].x.val;
				cnt[a[i].x.idx]++;
				choose[i] = 1;
			}
		}
		sort(a + 1, a + n + 1, cmp2);
		for (int i = 1; i <= n; ++i) {
			if (!choose[i] && cnt[a[i].y.idx] < n / 2) {
				ans += a[i].y.val;
				cnt[a[i].y.idx]++;
				choose[i] = 1;
			}
		}
		sort(a + 1, a + n + 1, cmp3);
		for (int i = 1; i <= n; ++i) {
			if (!choose[i] && cnt[a[i].z.idx] < n / 2) {
				ans += a[i].z.val;
				cnt[a[i].z.idx]++;
				choose[i] = 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}