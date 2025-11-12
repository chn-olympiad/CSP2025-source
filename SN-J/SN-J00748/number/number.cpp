// XGDFZ wsq
#include <bits/stdc++.h>
using namespace std;
#define int long long

namespace wsq {
	string s;
	int cnt[10];
	void main() {
		cin >> s;
		for(int i = 0; i < s.size(); i++)
			if('0' <= s[i] && s[i] <= '9') cnt[s[i] - '0']++;
		for(int i = 9; i >= 0; i--)
			for(int j = 0; j < cnt[i]; j++) cout << i;
		cout << endl;
	}
};

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int T = 1;
	// cin >> T;
	while(T--)
		wsq::main();
	return 0;
}
