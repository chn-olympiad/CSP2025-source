#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdin);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		if(n >= 1e5) { // –‘÷ Ae
			vector<int> club(n);
			for(int i = 0; i<n; ++i) {
				int t;
				cin >> club[i];
				cin >> t;
				cin >> t;
			}
			sort(club.begin(),club.end(),greater<int>());
			int ans = 0;
			for(int i = 0; i<n/2; ++i) {
				ans += club[i];
			}
			cout << ans << endl;
		} else {
			vector<vector<int>> stu(n,vector<int>(3));
			for(int i = 0; i<n; ++i) {
				for(int j = 0; j<3; ++j) {
					cin >> stu[i][j];
				}
			}
			int ans = -1;
			string state = "";
			unordered_map<string,int> bk;
			vector<int> vis(n+1);
			auto check = [&]()->void {
				int sum = 0;
				vis.assign(0,n+1);
				for(int i = 0; i<n; ++i) {
					int sel = state[i]-'0';
					vis[sel] = 1;
					sum += stu[i][sel];
				}
				ans = max(sum,ans);
			};
			vector<int> bucket(3);
			function <void()> dfs;
			dfs = [&]() {
				if(state.size() == n) {
					string ans = "";
					auto it = bk.find(state);
					if(it == bk.end()) {
						bk[state] = 1;
						check();
					}
					return;
				}
				for(int i = 0; i<=n; ++i) {
					int num = (i%10)%3;
					if(bucket[num] >= n/2) {
						continue;
					}
					state.push_back(num+'0');
					bucket[num]++;
					dfs();
					state.pop_back();
					bucket[num]--;
				}
			};
			dfs();
			cout << ans << endl;
		}
	}
		return 0;
	}
