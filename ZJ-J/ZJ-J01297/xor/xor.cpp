#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k, x, cnt = 0;
	cin >> n >> k;
	vector<int> a(n), pre(n);
	unordered_multiset<int> s;
	for (int i = 0;i < n;i++) {
		cin >> a[i];
		if (i == 0) pre[i] = a[i];
		else pre[i] = pre[i-1] ^ a[i];
	}
	int l = 0, r = 0;
	while (l < n && r < n) {
		int val = l == 0 ? pre[r] : pre[r] ^ pre[l-1];
		if (s.find(val ^ k) != s.end() || val == k) {
			if (val == k) cnt++;
			else cnt += s.count(val ^ k);
			s.clear();
			r++, l = r;
		} else {
			s.insert(pre[r]);
			r++;
		}
	}
	cout << cnt;
	return 0;
}
