/*
T1 club
招收了 n 个成员，n 为偶 数。
分到协会不同的部门。
三个部门，第 i 个成员对第 j个部门的满意度为 ai,j
一个分配方案的满意度为所有新成员对分配到的部门的满意度之和
在分配方案中，不存在一个部门被分配多于n/2个新成员。
求出满足他要求的分配方案的满
意度的最大值。

*/

#include <bits/stdc++.h>
using namespace std;
#define _for(i, a, b) for(int i = (a); i <= (b); ++i)
#define _rfo(i, a, b) for(int i = (a); i >= (b); --i)
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFO(i, a, b) for(int i = (a); i > (b); --i)
using LL = long long;
using VI = vector<int>;

void solve() {
	int n, ca = 0, cb = 0, cc = 0, ans = 0;
	scanf("%d", &n);
	vector<array<int, 4>> A(n);
	for (auto &a : A) {
		scanf("%d%d%d", &a[0], &a[1], &a[2]), a[3] = max({a[0], a[1], a[2]});
		(a[3] == a[0] ? ca : (a[3] == a[1] ? cb : cc))++, ans += a[3];
	}
	priority_queue<int> Q;
	if (ca <= n / 2) {
		if (cb <= n / 2) {
			if (cc <= n / 2)
				return cout << ans << "\n", void();
			else {
				for (auto &a : A)
					if (a[3] == a[2])
						Q.push(max(a[0], a[1]) - a[2]);
				_for(i, 1, cc - n / 2) ans += Q.top(), Q.pop();
			}
		} else {
			for (auto &a : A)
				if (a[3] == a[1])
					Q.push(max(a[0], a[2]) - a[1]);
			_for(i, 1, cb - n / 2) ans += Q.top(), Q.pop();
		}
	} else {
		for (auto &a : A)
			if (a[3] == a[0])
				Q.push(max(a[2], a[1]) - a[0]);
		_for(i, 1, ca - n / 2) ans += Q.top(), Q.pop();
	}
	cout << ans << "\n";
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}