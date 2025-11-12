#include <iostream>
#include <vector>
#include <cstdio>
#include <set>
#define ll long long
using namespace std;
int n, m;
ll mod = 998244353;
string s;
vector<int> nums;
ll res = 0;
void solve(const vector<int>& ans) {
	int rej = 0;
	int t = 0;
	for (int i = 1; i <= n; i++) {
		if (rej >= nums[ans[i]]) {
			rej++;
			continue;
		}
		if (s[i - 1] == '0') {
			rej++;
		}
		else {
			t++;
		}
	}
	if (t >= m) {
		res = (res + 1) % mod;
	}
	return;
}
void backtrack(vector<int>& ans, set<int>& vis, int index) {
	if (index == n + 1) {
		solve(ans);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (vis.find(i) == vis.end()) {
			ans[index] = i;
			vis.insert(i);
			backtrack(ans, vis, index + 1);
			vis.erase(i); 
		}
	} 
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cin >> s;
	nums.assign(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
	vector<int> ans(n + 1, 0);
	set<int> vis;
	backtrack(ans, vis, 1);
	cout << res << endl;
	return 0;
}
