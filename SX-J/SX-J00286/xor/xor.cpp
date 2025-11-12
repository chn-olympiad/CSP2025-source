#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define i128 _int128_t
#define endl "\n"
using vi = vector<int>;
using pii = pair<int, int>;
const int INF = 1e6+100;
const int MaxN = 1e9;
int sum = 0;
vi a;
vi vit; //是否被使用

struct XXX {
	int x, l, r;
};

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	a.assign(n + 1, {});
	vit.assign(n + 1, 0);
	queue<XXX> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == k) {
			sum++;
			vit[i] = 1;
		} else
			q.push({a[i], i, i});
	}
	while (!q.empty()) {
		XXX it = q.front();
		int x = it.x;
		int l = it.l;
		int r = it.r;
		q.pop();
		if (r + 1 > n)
			continue;
		if (vit[l])
			continue;
		if (vit[r + 1] || vit[r])
			continue;    //宽搜无需全判定
		if ((x ^ a[r + 1]) == k) {
			sum++;
			for (int i = l; i <= r + 1; i++) {
				vit[i] = 1;
			}
		} else
			q.push({(x ^a[r + 1]), l, r + 1});
	}
	cout << sum;
	return 0;
}