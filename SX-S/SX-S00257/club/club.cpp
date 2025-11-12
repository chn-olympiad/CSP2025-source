#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int a[100005][4];

struct node {
	int x, y, z;
};

bool cmp(node ff, node dd) {
	return ff.x > dd.x;
}
vector<node>vec[100005];

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < 100005; i++) {
			vec[i].clear();
		}
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			vec[i].push_back({a[i][1], 1, i});
			vec[i].push_back({a[i][2], 2, i});
			vec[i].push_back({a[i][3], 3, i});
			sort(vec[i].begin(), vec[i].end(), cmp);
		}
		int cnt[4] = {0, 0, 0, 0};
		int sum = 0;
		vector<int >v[4];
		for (int i = 1; i <= n; i++) {
			cnt[vec[i][0].y]++;
			v[vec[i][0].y].push_back(vec[i][0].z);
			sum += vec[i][0].x;
		}
		for (int i = 1; i <= 3; i++) {
			if (cnt[i] > n / 2) {
				vector<int>vv;
				for (int j = 0; j < v[i].size(); j++) {
					vv.push_back(vec[v[i][j]][0].x - vec[v[i][j]][1].x);
				}
				sort(vv.begin(), vv.end());
				int c = 0;
				while (cnt[i] > n / 2) {
					sum -= vv[c];
					c++;
					cnt[i]--;
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}
//CCF万岁!!!
//CCF全体老师，你们辛苦了！