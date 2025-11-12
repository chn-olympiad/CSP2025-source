#include <bits/stdc++.h>
using namespace std;
vector<int> nums;

bool cmp(int a, int b) {
	return a > b;
}

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			int u = s[i] - '0';
			nums.push_back(u);
			cnt++;
		}
	}
	sort(nums.begin(), nums.end(), cmp);
	for (int i = 0; i < cnt; i++) {
		cout << nums[i];
	}
	return 0;
}