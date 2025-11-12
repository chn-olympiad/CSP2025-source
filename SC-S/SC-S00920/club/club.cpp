/*****************/
/*  club.cpp     */
/*****************/
/* Not Perfect, Expect 10/20 */
#include <bits/stdc++.h>
using namespace std;
const string FILE_NAME = "club";
ifstream is(FILE_NAME + ".in");
ofstream os(FILE_NAME + ".out");
//#define is cin
//#define os cout
int arr[31][4], n, c[4];
int dfs(int i, int j){
	if(i == n) {
		return arr[i][j];
	}
	c[j]++;
	int res = arr[i][j] + max({
		c[1] < n / 2 ? dfs(i + 1, 1) : 0,	
		c[2] < n / 2 ? dfs(i + 1, 2) : 0,	
		c[3] < n / 2 ? dfs(i + 1, 3) : 0,	
	});
	c[j]--;
	return res;
};
int main() {
	ios::sync_with_stdio(0);
	is.tie(0);
	os.tie(0);
	int t;
	is >> t;
	while (t--) {
		is >> n;
		if(n <= 30) {
			for(int i = 1; i <= n; ++i) {
				is >> arr[i][1]
				   >> arr[i][2]
				   >> arr[i][3];
			}
			int ans = 0;
			os << dfs(0, 0) << "\n";
			continue;
		}
		
		vector<tuple<int, int, int>> vec;
		vector<bool> joined(n + 1, 0);
		int cnt[4] = {0, 0, 0, 0};
		int tmp[4];
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			is >> tmp[1] >> tmp[2] >> tmp[3];
			tmp[0] = min({tmp[1], tmp[2]});
			vec.push_back({tmp[1] - tmp[0], 1, i});
			vec.push_back({tmp[2] - tmp[0], 2, i});
			vec.push_back({tmp[3] - tmp[0], 3, i});
			ans += tmp[0];
		}
		sort(vec.begin(), vec.end(), greater<tuple<int, int, int>>());
		for (auto [val, typ, uid] : vec) {
			if (joined[uid]) continue;
			if (cnt[typ] >= n / 2) continue;
			ans += val;
			cnt[typ]++;
			joined[uid] = true;
		}
		os << ans << "\n";
	}
	return 0;
}