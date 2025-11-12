#include <bits/stdc++.h>
using namespace std;
long long n;
vector<pair<long long, int>> a[100005];

bool cmp(pair<long long, int> x, pair<long long, int> y) {
	return x.first > y.first;
}
priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<pair<long long, pair<int, int>>>>
        q1;
priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<pair<long long, pair<int, int>>>>
        q3;
priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<pair<long long, pair<int, int>>>>
        q2;
long long t;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		memset(a, 0, sizeof(a));
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				int y;
				cin >> y;
				a[i].push_back({y, j});
			}

			sort(a[i].begin(), a[i].end(), cmp);
			a[i].push_back({-0x3f3f3f3f, 4});
			if (a[i][0].second == 1)
				q1.push({a[i][0].first - a[i][1].first, {i, 0}});
			if (a[i][0].second == 2)
				q2.push({a[i][0].first - a[i][1].first, {i, 0}});
			if (a[i][0].second == 3)
				q3.push({a[i][0].first - a[i][1].first, {i, 0}});
		}
		while (q1.size() > n / 2) {
			pair<long long, pair<int, int>> f = q1.top();
			if (a[f.second.first][f.second.second + 1].second == 2)
				q2.push({a[f.second.first][f.second.second + 1].first - a[f.second.first][f.second.second + 1 + 1].first, {f.second.first, f.second.second + 1}});
			else
				q3.push({a[f.second.first][f.second.second + 1].first - a[f.second.first][f.second.second + 1 + 1].first, {f.second.first, f.second.second + 1}});
			q1.pop();
		}
		while (q2.size() > n / 2) {
			pair<long long, pair<int, int>> f = q2.top();
			if (a[f.second.first][f.second.second + 1].second == 3)
				q3.push({a[f.second.first][f.second.second + 1].first - a[f.second.first][f.second.second + 1 + 1].first, {f.second.first, f.second.second + 1}});
			else
				q1.push({a[f.second.first][f.second.second + 1].first - a[f.second.first][f.second.second + 1 + 1].first, {f.second.first, f.second.second + 1}});
			q2.pop();
		}
		while (q3.size() > n / 2) {
			pair<long long, pair<int, int>> f = q3.top();
			if (a[f.second.first][f.second.second + 1].second == 2)
				q2.push({a[f.second.first][f.second.second + 1].first - a[f.second.first][f.second.second + 1 + 1].first, {f.second.first, f.second.second + 1}});
			else
				q1.push({a[f.second.first][f.second.second + 1].first - a[f.second.first][f.second.second + 1 + 1].first, {f.second.first, f.second.second + 1}});
			q3.pop();
		}
		long long ans = 0;
		while (q1.size()) {
			ans += a[q1.top().second.first][q1.top().second.second].first;
			q1.pop();
		}
		while (q2.size()) {
			ans += a[q2.top().second.first][q2.top().second.second].first;
			q2.pop();
		}
		while (q3.size()) {
			ans += a[q3.top().second.first][q3.top().second.second].first;
			q3.pop();
		}
		cout << ans << endl;
	}
	return 0;
}