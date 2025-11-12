#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	int n, k; // 两个非负整数n, k，分别表示小R 的序列长度和小X 给小R 的非负整数。
	cin >> n >> k;
	vector<int> l;
	vector<int> p; // 前缀异或和数组
	vector<bool> judge(n, false);

	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		l.push_back(t);
	}

	for (int i = 0; i < n; i++) {
		if (i == 0) {
			p.push_back(l[i]);
			continue;
		} else {
			p.push_back(p[i - 1] xor l[i]);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if ((i == j) && (i != 0) && ((p[j] xor p[i - 1]) == k) && (judge[i] != true) && (judge[j] != true)) {
				judge[i] = true;
				ans++;
			} else if ((i == 0) && (p[j] == k) && (judge[i] != true) && (judge[j] != true)) {
				for (int x = i; x <= j; x++) {
					judge[x] = true;
				}
				ans++;
			} else if (((p[j] xor p[i - 1]) == k) && (judge[i] != true) && (judge[j] != true)) {
				for (int x = i; x <= j; x++) {
					judge[x] = true;
				}
				ans++;
			}
		}
	}

	cout << ans;
	return 0;
}