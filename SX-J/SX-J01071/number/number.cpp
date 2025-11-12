#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	cin >> s;
	vector<int> num;
	for (auto i : s)
		if (i <= '9' && i >= '0')
			num.push_back(static_cast<int>(i) - 48);
	sort(num.begin(), num.end(), greater<int>());
	for (auto ans : num)
		cout << ans;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
//	int T;
//	cin >> T;
//	while (T--) {
//		solve();
//	}
	solve();
	return 0;
}