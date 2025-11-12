#include <bits/stdc++.h>
using namespace std;
#define int long long
int nums[5010], h[5010];
int n, cnt = 0;
const int mod = 998244353;
int jcz[5010], jcn[5010];

inline int ksm(int a, int b) {
	int res = 1;
	if (b == 0)
		return res;
	if (b & 1) {
		res = a * ksm(a, b - 1) % mod;
	} else {
		res = ksm(a, b / 2);
		res = res * res % mod;
	}
	return res;
}

bool cmp(int a, int b) {
	return a < b;
}

void jiecny() {
	jcz[0] = 1;
	jcn[0] = 1;
	for (int i = 1; i <= n; i++) {
		jcz[i] = jcz[i - 1] * i % mod;
		jcn[i] = ksm(jcz[i], mod - 2);
	}
}

inline int zhs(int a, int b) {
	if (b < 0 || b > a)
		return 0;
	int u = ((jcz[a] % mod) * (jcn[b] % mod) * (jcn[a - b] % mod)) % mod;
	return u;
}

int ef(int l, int r, int x) {
	while (l < r - 1) {
		int mid = (l + r) / 2;
		if (h[mid] > x)
			r = mid;
		else
			l = mid;
	}
	if (h[l] > x)
		return l;
	else if (h[r] > x)
		return r;
	else
		return -1;
}

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	jiecny();
	for (int i = 1; i <= n; i++)
		cin >> nums[i];
	//sort(nums + 1, nums + 1 + n, cmp);
	//for (int i = 1; i <= n; i++)
	//	h[i] = h[i - 1] + nums[i];
	for (int i = 3; i <= n; i++) {
		int ans = 0;
		//int u = ef(1, i - 1, nums[i]);
		//cout << u << " ";
		//if (u == -1) {
		//	cout << endl;
		//	continue;
		//}
		//	int minlen = u, dqlen = u, dqh = h[u];
		//int ll = 1, rr = u, minll = 1, minrr = u;
		//while (ll < rr || rr < i - 1) {
		//	while (dqh > nums[i] && ll < rr) {
		//		if (dqlen < minlen && ll <= rr && rr <= i - 1) {
		//			minlen = dqlen;
		//			minll = ll;
		//			minrr = rr;
		//		}
		//		dqh -= nums[ll];
		//		ll++;
		//		dqlen--;
		//		cout << "*";
		//	}
		//	while (dqh <= nums[i] && rr <= i - 1) {
		//		dqh += nums[rr];
		//		rr++;
		//		dqlen++;
		//		cout << "/";
		//	}
		//	cout << ll << " " << rr << " " << dqlen;
		//	if (dqlen < minlen && ll <= rr && rr <= i - 1) {
		//		minlen = dqlen;
		//		minll = ll;
		//		minrr = rr;
		//	}
		//}
		//cout << "aaa";
		//ans += i - minrr;
		for (int j = 2; j <= i - 1; j++) {
			ans = (ans % mod + zhs(i - 1, j) % mod) % mod;
		}
		cnt = (cnt % mod + ans % mod) % mod;
		//cout << minll << " " << minrr << " " << minlen << " " << ans << endl;
	}
	cout << cnt;
	return 0;
}