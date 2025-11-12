#include <bits/stdc++.h>
#define ll long long
#define db double
#define i128 __int128
#define AKIOI ios::sync_with_stdio(false);cin.tie(0),cout.tie(0)
using namespace std;
ll n, k, a[500005], s[500005], o, d = 1, ans;

struct node {
	ll l, r;
} b[500005];

bool cmp(node p, node q) {
	if (p.r != q.r)
		return p.r < q.r;
	else
		return p.l > q.l;
}

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	AKIOI;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = (s[i - 1]) ^ (a[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if ((s[i - 1] ^ s[j]) == k) {
				o++;
				b[o].l = i;
				b[o].r = j;
			}
		}
	}
	sort(b + 1, b + o + 1, cmp);
	for (int i = 1; i <= n && d <= o;) {
		while (b[d].l < i)
			d++;
		ans++;
		i = b[d].r;
	}
	cout << ans;
	return 0;
}
/*
部分分：模拟，about 50pts
全解：双指针，priority_queue，滑动窗口 100pts (存疑)

主体思路：类似前缀和，即 a3 xor a4 = (a1 xor a2) xor (a1 xor a2 xor a3 xor a4)
这样看来，其实就是一个O(n^2)（可优化）区间遍历+线段覆盖（lg 凌乱的yyy）的题目。

expected:40pts+
*/