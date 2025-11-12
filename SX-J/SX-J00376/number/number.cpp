#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {

	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	string s;
	cin >> s;

	vector<int> vi;

	for (int i = 0; i < (int)s.length(); i ++ ) {
		if (s[i] >= '0' && s[i] <= '9' )
			vi.push_back(s[i] - '0');
	}

	sort(vi.begin(), vi.end());
	reverse(vi.begin(), vi.end());

	for (int i = 0; i < (int)vi.size(); i ++ ) {
		printf("%lld", vi[i]);
	}

	return 0;
}
