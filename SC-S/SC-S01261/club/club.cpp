// 白鹭霜华。
// 绫华保佑我。

// 怎么 1.5h 还没做出 T1，唉唉。
// 我的 OI 水平也就那样了吧。

// 到底是 dp 还是贪心呢？每个都想过了但是都错了。应该就是贪心吧。dp 状态太多了不太能优化。
// 我状态定义的有问题吧？可能有更优的状态定义。

// 终究还是做不到啊。
// 先稳住心态。先打后面的暴力。

// 奋战 4h 依然没做出。绝望了。
// NOIP 又会考成什么样呢？
// 想了好几种 dp 状态都是假的。
// T2 也不会正解。好难受。
#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f3f3f3f3f;
int T, n, cnt[3], num_cnt[3], num[15], idx;
struct NODE {
	pii d[3];
	int cnt;
	bool operator < (const NODE &h) const {
		return (cnt == h.cnt) ? (d[0].first > h.d[0].first) : (cnt > h.cnt);
	}
} arr[maxn];

bool cmp(const pii &x, const pii &y) {
	return x.first > y.first;
}

inline void turn3(int x) {
	idx = num_cnt[0] = num_cnt[1] = num_cnt[2] = 0;
	memset(num, 0, sizeof(num));
	while(x) {
		num[++idx] = x % 3;
		num_cnt[num[idx]]++;
		x /= 3;
	}
	if (!idx) {
		num_cnt[0] = n;
	}
}

inline int quickPow(int x, int p) {
	int ret = 1;
	for (; p; p >>= 1) {
		if (p & 1) {
			ret = ret * x;
		}
		x = x * x;
	}
	return ret;
}

void init() {
	cnt[0] = cnt[1] = cnt[2] = 0;
	for (int i = 1; i <= n; i++) {
		arr[i].cnt = 0;
	}
}

void solve() {
	scanf ("%lld", &n);
	init();
	if (n <= 10) {
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 3; j++) {
				scanf ("%lld", &arr[i].d[j].first);
				arr[i].d[j].second = j;
			}
		}
		int lim = quickPow(3, n), ans = 0;
		for (int st = 0; st < lim; st++) {
			turn3(st);
			if (num_cnt[0] > n / 2 || num_cnt[1] > n / 2 || num_cnt[2] > n / 2) {
				continue;
			}
			int ret = 0;
			for (int i = 1; i <= n; i++) {
				if (num[i] == 0) {
					ret += arr[i].d[0].first;
				}
				if (num[i] == 1) {
					ret += arr[i].d[1].first;
				}
				if (num[i] == 2) {
					ret += arr[i].d[2].first;
				}
			}
			ans = max(ans, ret);
		}
		printf ("%lld\n", ans);
		return;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			scanf ("%lld", &arr[i].d[j].first);
			arr[i].d[j].second = j;
			arr[i].cnt += (arr[i].d[j].first == 0);
		}
		sort(arr[i].d, arr[i].d + 3, cmp);
	}
	sort(arr + 1, arr + n + 1);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
//		cout << arr[i].cnt << endl;
		pii x = arr[i].d[0], y = arr[i].d[1], z = arr[i].d[2];
		if (cnt[x.second] < n / 2) {
			ans += x.first;
			cnt[x.second]++;
		}
		else if (cnt[y.second] < n / 2) {
			ans += y.first;
			cnt[y.second]++;
		}
		else if (cnt[z.second] < n / 2) {
			ans += z.first;
			cnt[z.second]++;
		}
	}
	printf ("%lld\n", ans);
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf ("%lld", &T);
	while (T--) {
		solve();
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/