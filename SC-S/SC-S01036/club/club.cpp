#include <bits/stdc++.h>
#define int long long
#define endl "\n"

using std::cin;
using std::cout;

struct node{
	int first, second, third;
};

node a[100001];

bool cmp(node a, node b) {
	int maxA = std::max({a.first, a.second, a.third});
	int maxB = std::max({b.first, b.second, b.third});
	return maxA > maxB;
}

signed main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		bool flag = true;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].first >> a[i].second >> a[i].third;
			if (a[i].second != 0 || a[i].third != 0) {
				flag = false;
			}
		}
		if (n == 2) {
			int a1 = a[1].first + a[2].second;
			int a2 = a[1].first + a[2].third;
			int a3 = a[1].second + a[2].third;
			int a4 = a[1].second + a[2].first;
			int a5 = a[1].third + a[2].first;
			int a6 = a[1].third + a[2].second;
			cout << std::max({a1, a2, a3, a4, a5, a6});
			continue;
		}
		else if (flag) {
			std::sort(a + 1, a + n + 1, cmp);
			int sum = 0;
			for (int i = 1; i <= n / 2; i++) {
				sum += a[i].first;
			}
			cout << sum;
			continue;
		}
		std::sort(a + 1, a + n + 1, cmp);
		int cnt1 = 0, cnt2 = 0, cnt3 = 0, sum = 0;
		for (int i = 1; i <= n; i++) {
			int m = std::max({a[i].first, a[i].second, a[i].third});
			if (m == a[i].first) {
				if (cnt1 < n / 2) {
					cnt1++;
					sum += m;
					a[i].first = a[i].second = a[i].third = -1;
				}
				else {
					a[i].first = -1;
				}
			}
			else if (m == a[i].second) {
				if (cnt2 < n / 2) {
					cnt2++;
					sum += m;
					a[i].first = a[i].second = a[i].third = -1;
				}
				else {
					a[i].second = -1;
				}
			}
			else {
				if (cnt3 < n / 2) {
					cnt3++;
					sum += m;
					a[i].first = a[i].second = a[i].third = -1;
				}
				else {
					a[i].third = -1;
				}
			}
		}
		std::sort(a + 1, a + n + 1, cmp);
		for (int i = 1; i <= n; i++) {
			int m = std::max({a[i].first, a[i].second, a[i].third});
			if (m == -1) {
				break;
			}
			if (m == a[i].first) {
				if (cnt1 < n / 2) {
					cnt1++;
					sum += m;
					a[i].first = a[i].second = a[i].third = -1;
				}
				else {
					a[i].first = -1;
				}
			}
			else if (m == a[i].second) {
				if (cnt2 < n / 2) {
					cnt2++;
					sum += m;
					a[i].first = a[i].second = a[i].third = -1;
				}
				else {
					a[i].second = -1;
				}
			}
			else {
				if (cnt3 < n / 2) {
					cnt3++;
					sum += m;
					a[i].first = a[i].second = a[i].third = -1;
				}
				else {
					a[i].third = -1;
				}
			}
		}
		std::sort(a + 1, a + n + 1, cmp);
		for (int i = 1; i <= n; i++) {
			int m = std::max({a[i].first, a[i].second, a[i].third});
			if (m == -1) {
				break;
			}
			if (m == a[i].first) {
				if (cnt1 < n / 2) {
					cnt1++;
					sum += m;
					a[i].first = a[i].second = a[i].third = -1;
				}
				else {
					a[i].first = -1;
				}
			}
			else if (m == a[i].second) {
				if (cnt2 < n / 2) {
					cnt2++;
					sum += m;
					a[i].first = a[i].second = a[i].third = -1;
				}
				else {
					a[i].second = -1;
				}
			}
			else {
				if (cnt3 < n / 2) {
					cnt3++;
					sum += m;
					a[i].first = a[i].second = a[i].third = -1;
				}
				else {
					a[i].third = -1;
				}
			}
		}
		cout << sum << endl;
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