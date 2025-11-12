#include <algorithm>
#include <cstdint>
#include <iostream>
#include <set>
#include <vector>
#define endl '\n'

using namespace std;

using ll = int64_t;
using pll = pair<ll, ll>;

struct node {
	int x, y, ansid;
};

constexpr ll base = 131, mod = 998244353;
constexpr int N = 2e5 + 10, M = 5e6 + 10;
int n, m, ls[N], llen;
multiset<pll> s;
vector<node> vec[N << 1];
ll b[M], h1[M], h2[M], ans[N];

namespace CDQ {
	node a[N << 1];
	int idx, valen;
	int val[N << 2], c[N << 2];

	void init() { idx = 0; }
	void push(const node& v) {
		a[++idx] = v;
	}

	void update(int k, int x) {
		for (; k <= valen; k += k & -k)
			c[k] += x;
	}
	int query(int k) {
		int res = 0;
		for (; k; k -= k & -k)
			res += c[k];
		return res;
	}

	void work() {
		valen = 0;
		for (int i = 1; i <= idx; i++)
			val[++valen] = a[i].y;
		sort(val + 1, val + valen + 1);
		valen = unique(val + 1, val + valen + 1) - val - 1;
		for (int i = 1; i <= valen; i++) c[i] = 0;
		sort(a + 1, a + idx + 1, [](const node& i, const node& j) {
			return i.x == j.x ? i.y < j.y : i.x < j.x;
		});
		for (int i = 1; i <= idx; i++) {
			if (a[i].ansid) {
				ans[a[i].ansid] = query(lower_bound(val + 1, val + valen + 1, a[i].y) - val);
			} else {
				update(lower_bound(val + 1, val + valen + 1, a[i].y) - val, 1);
			}
		}
	}
};

bool checkB(const string& str) {
	int cb = 0;
	for (char i : str)
		if ((i != 'a' && i != 'b') || ((cb += (i == 'b')) > 1))
			return false;
	return cb == 1;
}

ll gethash(const string& str) {
	ll res = 0;
	for (char i : str)
		res = (res * base % mod + (i - 'a' + 5)) % mod;
	return res;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	b[0] = 1;
	for (int i = 1; i < M; i++)
		b[i] = b[i - 1] * base % mod;
	cin >> n >> m;
	bool taskB = true;
	for (int i = 1; i <= n; i++) {
		static string a, b;
		cin >> a >> b;
		s.emplace(gethash(a), gethash(b));
		ls[i] = a.size();
		taskB = taskB && checkB(a) && checkB(b);
		if (taskB) {
			int pba = 1, pbb = 1;
			for (int j = 2; j <= ls[i]; j++) {
				if (a[j - 1] == 'b') pba = j;
				if (b[j - 1] == 'b') pbb = j;
			}
			vec[pba - pbb + N].push_back(node{min(pba, pbb) - 1, ls[i] - max(pba, pbb), 0});
		}
	}
	sort(ls + 1, ls + n + 1);
	llen = unique(ls + 1, ls + n + 1) - ls - 1;
	for (int kase = 1; kase <= m; kase++) {
		static string s1, s2;
		cin >> s1 >> s2;
		int k = s1.size();
		if (taskB && checkB(s1) && checkB(s2)) {
			int pba = 1, pbb = 1;
			for (int i = 2; i <= k; i++) {
				if (s1[i - 1] == 'b') pba = i;
				if (s2[i - 1] == 'b') pbb = i;
			}
			vec[pba - pbb + N].push_back(node{min(pba, pbb) - 1, k - max(pba, pbb), kase});
			continue;
		}
		for (int i = 1; i <= k; i++)
			h1[i] = (h1[i - 1] * base % mod + (s1[i - 1] - 'a' + 5)) % mod,
			h2[i] = (h2[i - 1] * base % mod + (s2[i - 1] - 'a' + 5)) % mod;
		int dl = k, dr = 1;
		for (int i = 1; i <= k; i++)
			if (s1[i - 1] != s2[i - 1])
				dl = min(dl, i), dr = max(dr, i);
		ll res = 0;
		for (int li = 1; li <= llen; li++)
			if (ls[li] >= dr - dl + 1 && ls[li] <= k)
				for (int i = max(1, dr - ls[li] + 1), j = max(ls[li], dr); i <= dl && j <= k; i++, j++)
					res += s.count(make_pair((h1[j] + mod - h1[i - 1] * b[j - i + 1] % mod) % mod,
											 (h2[j] + mod - h2[i - 1] * b[j - i + 1] % mod) % mod));
		ans[kase] = res;
	}
	if (taskB) {
		for (int i = 0; i < (N << 1); i++) {
			if (vec[i].size() && vec[i].back().ansid) {
				CDQ::init();
				for (const node& j : vec[i])
					CDQ::push(j);
				CDQ::work();
			}
		}
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << endl;
	return 0;
}
