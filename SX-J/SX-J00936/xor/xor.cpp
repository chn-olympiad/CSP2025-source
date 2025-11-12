#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 500005;
int n, k;
int a[N], s[N];
unordered_map<int, int>mp;
unordered_map<int, bool>vis;
int cnt;

struct node {
	int l, r;
} ans[N];

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = a[i] ^ s[i - 1];
	}
	vis[0] = 1;
	for (int i = 1; i <= n; i++) {
		int t = k ^s[i];
		if (vis[t]) {
			ans[++cnt] = {mp[t] + 1, i};
		}
		mp[s[i]] = i;
		vis[s[i]] = 1;
	}
	int lst = 0, sum = 0;
	for (int i = 1; i <= cnt; i++) {
		if (ans[i].l > lst) {
			sum++;
			lst = ans[i].r;
		}
	}
	cout << sum;
	return 0;
}
/*
4 0
2 1 0 3
*/