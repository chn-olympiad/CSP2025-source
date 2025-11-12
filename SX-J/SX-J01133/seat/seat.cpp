#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	vector<int> g;
	int n, m; // 两个正整数 n,m，分别表示小 R 所在的考场座位的行数与列数。
	cin >> n >> m;
	int s = n * m;

	for (int i = 0; i < s; i++) {
		int t;
		cin >> t;
		g.push_back(t);
	}

	int a1 = g[0];
	sort(g.begin(), g.end(), cmp);

	int index = 0;
	for (int i = 0; i < s; i++) {
		if (g[i] == a1) {
			index = i;
			break;
		}
	}
	index++;

	int c = ceil(double(index) / double(n));
	int r = 0;
	if (c % 2 == 0) {
		r = (index % n) + n - (index % n);
	} else {
		if (index % n == 0) {
			r = n;
		} else {
			r = index % n;
		}
	}
	cout << c << ' ' << r;
	return 0;
}