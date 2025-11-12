#include <iostream>
#include <vector>
#include <functional>
#include <string>

using namespace std;

using lls = long long;

const long long mod = 998244353;

int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	lls n,m;
	cin >> n >> m;
	vector<lls> vis(n+1);
	vector<lls> state(1);
	vector<lls> diff(n+1),c(n+1);
	string input;
	cin >> input;
	for(lls i = 1; i<=n; ++i) {
		diff[i] = input[i-1] - '0';
	}
	for(lls i = 1; i<=n; ++i) {
		cin >> c[i];
	}
	function <void()> dfs;
	auto check = [&]() {
		lls cnt = 0;
		vector<lls> block(n+1,0);
		vector<int> giveup(n+1,0);
		for(lls i = 1; i<=n; ++i) {
			if(diff[i] == 0) {
				block[state[i]] = 1;
			}
			block[i] += block[i-1];
			if(block[i] < c[i]){
				block[i]++;
				giveup[state[i]] = 1;
			}
		}
		for(lls i = 1; i<=n; ++i) {
			if(giveup[state[i]] != 0) {
				++cnt;
			}
		}
		return cnt >= m;
	};
	lls ans = 0;
	dfs = [&]() {
		if(state.size() == n+1) {
			if(check () == true)
				++ans;
				ans %= mod;
			return;
		}
		for(lls i = 1; i<=n; ++i) {
			if(vis[i] != 0) {
				continue;
			}
			vis[i] = 1;
			state.push_back(i);
			dfs();
			state.pop_back();
			vis[i] = 0;
		}
	};
	dfs();
	cout << ans << endl;
	return 0;
}
