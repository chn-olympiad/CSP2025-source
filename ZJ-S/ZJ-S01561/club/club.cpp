#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v first
#define k second
#define pi pair<int, int>
#define vpi vector<pi>
#define vvpi vector<vpi>
#define vi vector<int>
#define vvi vector<vi>
int t, n, a[100010][5];
ll ans;
void dfs(int i, int h1, int h2, int h3, ll sum) {
	if (i == n + 1) {
		ans = max(ans, sum);
		return;
	} 
	if (h1 < n / 2) dfs(i + 1, h1 + 1, h2, h3, sum + a[i][1]);
	if (h2 < n / 2) dfs(i + 1, h1, h2 + 1, h3, sum + a[i][2]);
	if (h3 < n / 2) dfs(i + 1, h1, h2, h3 + 1, sum + a[i][3]);
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t -- ) {
		cin >> n;
		bool f1 = 0, f2 = 0;
		for (int i = 1; i <= n; i ++ ) {
			for (int j = 1; j <= 3; j ++ ) cin >> a[i][j];
			if (a[i][2] != 0) f1 = 1;
			if (a[i][3] != 0) f2 = 1;
		}
		if (!f1) {
			vector<int> vec;
			for (int i = 1; i <= n; i ++ ) vec.push_back(a[i][1]);
			sort(vec.rbegin(), vec.rend());
			ll oo = 0;
			for (int i = 1; i <= n / 2; i ++ ) oo += vec[i - 1];
			cout << oo << "\n";
		} else if (!f2) {
			priority_queue<pair<int, int>> vec1, vec2;
			for (int i = 1; i <= n; i ++ ) {
				vec1.push({a[i][1], i});
				vec2.push({a[i][2], i});
			}
			map<int, bool> mp;
			ll oo = 0;
			int li = n / 2, vec1_h = 0, vec2_h = 0;
			while (n -- ) {
				while (mp[vec1.top().k]) vec1.pop();
				while (mp[vec2.top().k]) vec2.pop();
				if (vec1.top().v > vec2.top().v || vec2_h >= li) {
					vec1_h ++;
					mp[vec1.top().k] = 1;
					oo += vec1.top().v;
					vec1.pop();
				} else {
					vec2_h ++;
					mp[vec2.top().k] = 1;
					oo += vec2.top().v;
					vec2.pop();
				}
			}
			cout << oo << "\n";
		} else {
			ans = 0;
			dfs(1, 0, 0, 0, 0);
			/*priority_queue<pair<int, int>> vec1, vec2, vec3;
			for (int i = 1; i <= n; i ++ ) {
				vec1.push({a[i][1], i});
				vec2.push({a[i][2], i});
				vec3.push({a[i][3], i});
			}
			map<int, bool> mp;
			int li = n / 2, vec1_h = 0, vec2_h = 0, vec3_h = 0;
			while (n -- ) {
				while (mp[vec1.top().k]) vec1.pop();
				while (mp[vec2.top().k]) vec2.pop();
				while (mp[vec3.top().k]) vec3.pop();
				// cout << vec1.top().v << ", " << vec1.top().k << "  " << vec2.top().v << ", " << vec2.top().k << "  " << vec3.top().v << ", " << vec3.top().k << "\n";
				if ((vec1.top().v >= vec2.top().v && vec1.top().v >= vec2.top().v && vec1_h < li) || (vec2_h >= li && vec1.top().v > vec3.top().v) || (vec3_h >= li && vec1.top().v > vec2.top().v)) {
					vec1_h ++;
					mp[vec1.top().k] = 1;
					ans += vec1.top().v;
					vec1.pop();
				} else if ((vec2.top().v >= vec1.top().v && vec2.top().v >= vec3.top().v && vec2_h < li) || (vec1_h >= li && vec2.top().v > vec3.top().v) || (vec3_h >= li && vec2.top().v > vec1.top().v)) {
					vec2_h ++;
					mp[vec2.top().k] = 1;
					ans += vec2.top().v;
					vec2.pop();
				} else {
					vec3_h ++;
					mp[vec3.top().k] = 1;
					ans += vec3.top().v;
					vec2.pop();
				}
			}*/
			cout << ans << "\n";
		}
	}
	return 0;
}
/*
10->1 9->1 8->1
4->2  0->2 0->3
*/