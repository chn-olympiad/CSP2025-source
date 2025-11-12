#include <bits/stdc++.h>
#define int long long
using namespace std;

struct node {
	int f, t, s;
} a[100010];
int cd[100010];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		int n;
		vector<pair<int, int>> v1, v2, v3;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].f >> a[i].s >> a[i].t;
			if (a[i].f >= a[i].s and a[i].f >= a[i].t) {
				v1.push_back({a[i].f, i});
				if (a[i].t >= a[i].s)
					cd[i] = a[i].t;
				else
					cd[i] = a[i].s;
			} else if (a[i].s >= a[i].f and a[i].s >= a[i].t) {
				v2.push_back({a[i].s, i});
				if (a[i].f >= a[i].t)
					cd[i] = a[i].f;
				else
					cd[i] = a[i].t;
			} else {
				v3.push_back({a[i].t, i});
				if (a[i].f >= a[i].s)
					cd[i] = a[i].f;
				else
					cd[i] = a[i].s;
			}



		}
//		cout << v1.size() << ' ' << v2.size() << ' ' << v3.size();
//		for (pair<int, int> i : v1) {
//
//			cout << i.first << ' ' << endl;
//		}
		if (v1.size() <= n / 2 and v2.size() <= n / 2 and v3.size() <= n / 2) {
			int sum = 0;
			for (pair<int, int> i : v1)
				sum += i.first;
			for (pair<int, int> i : v2)
				sum += i.first;
			for (pair<int, int> i : v3)
				sum += i.first;
			cout << sum << endl;
			continue;
		}
//		sort(v1.begin(), v1.end());
//		sort(v2.begin(), v2.end());
//		sort(v3.begin(), v3.end());
		if (v1.size() > n / 2) {
			vector<pair<int, int>> v4;
			for (int i = 0; i < v1.size(); i++) {
				v4.push_back({v1[i].first - cd[v1[i].second], i});
			}
			sort(v4.begin(), v4.end());
			int cnt = v1.size();
			for (int i = 0; i < v4.size(); i++) {
				v1[v4[i].second].first = cd[v1[v4[i].second].second];
				cnt--;
				if (cnt == n / 2)
					break;
			}
		} else if (v2.size() > n / 2) {
			vector<pair<int, int>> v4;
			for (int i = 0; i < v2.size(); i++) {
				v4.push_back({v2[i].first - cd[v2[i].second], i});
//				cout << v2[i].first - cd[v2[i].second] << ' ' << i  << endl;
			}
			sort(v4.begin(), v4.end());
			int cnt = v2.size();
			for (int i = 0; i < v4.size(); i++) {
				v2[v4[i].second].first = cd[v2[v4[i].second].second];
				cnt--;
				if (cnt == n / 2)
					break;
			}
		} else {
			vector<pair<int, int>> v4;
			for (int i = 0; i < v3.size(); i++) {
				v4.push_back({v3[i].first - cd[v3[i].second], i});
			}
			sort(v4.begin(), v4.end());
			int cnt = v3.size();
			for (int i = 0; i < v4.size(); i++) {
				v3[v4[i].second].first = cd[v3[v4[i].second].second];
				cnt--;
				if (cnt == n / 2)
					break;
			}
		}
		int sum = 0;
		for (pair<int, int> i : v1)
			sum += i.first;
		for (pair<int, int> i : v2)
			sum += i.first;
		for (pair<int, int> i : v3)
			sum += i.first;
		cout << sum << endl;
		continue;
	}
	return 0;
}
