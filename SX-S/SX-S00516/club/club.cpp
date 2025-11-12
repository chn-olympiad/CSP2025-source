#include <bits/stdc++.h>
using namespace std;
int t, n, ans, cnum[3];

struct node {
	int x, id;
} club[100005][3];

struct ddata {
	int xx, idd;
};

bool cmp(node a, node b) {
	return a.x > b.x;
}

bool cmp2(ddata a, ddata b) {
	return a.xx > b.xx;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		ans = 0;
		memset(cnum, 0, sizeof(cnum));
		vector<ddata> vt[3];
		vector<ddata> vt2[3];
		vector<ddata> vt3[3];
		map<int, int> mp;
		for (int i = 1; i <= n; i++) {
			cin >> club[i][0].x >> club[i][1].x >> club[i][2].x;
			club[i][0].id = 0;
			club[i][1].id = 1;
			club[i][2].id = 2;
			sort(club[i], club[i] + 3, cmp);
		}
		for (int i = 1; i <= n; i++) {
			vt[club[i][0].id].push_back({club[i][0].x, i});
			vt2[club[i][1].id].push_back({club[i][1].x, i});
			vt3[club[i][2].id].push_back({club[i][2].x, i});
		}
		for (int i = 0; i < 3; i++) {
			sort(vt[i].begin(), vt[i].end(), cmp2);
			sort(vt2[i].begin(), vt2[i].end(), cmp2);
			sort(vt3[i].begin(), vt3[i].end(), cmp2);
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < vt[i].size(); j++) {
				if (cnum[club[vt[i][j].idd][0].id] < n / 2) {
					cnum[club[vt[i][j].idd][0].id]++;
					mp[vt[i][j].idd]++;
					ans += vt[i][j].xx;
				}
			}
		}
		if (mp.size() < n) {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < vt2[i].size(); j++) {
					if (mp[vt2[i][j].idd] > 0)
						continue;
					if (cnum[club[vt2[i][j].idd][1].id] < n / 2) {
						cnum[club[vt2[i][j].idd][1].id]++;
						mp[vt2[i][j].idd]++;
						ans += vt2[i][j].xx;
					}
				}
			}
		}
		if (mp.size() < n) {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < vt3[i].size(); j++) {
					if (mp[vt3[i][j].idd] > 0)
						continue;
					if (cnum[club[vt3[i][j].idd][2].id] < n / 2) {
						cnum[club[vt2[i][j].idd][2].id]++;
						mp[vt3[i][j].idd]++;
						ans += vt3[i][j].xx;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;

}
