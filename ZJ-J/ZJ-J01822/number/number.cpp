#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define upl(i, s, t, d) for(int i = (s); i <= (t); i += d)
#define dol(i, s, t, d) for(int i = (s); i >= (t); i -= d)
//#define int long long
void INIT() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
}

signed main() {
	INIT();
	
	string s, ans = "";
	cin >> s;
	int ls = s.length();
	upl(i, 0, ls, 1) {
		if(isdigit(s[i]))
			ans += s[i];
	}
	sort(ans.begin(), ans.end(), greater<char>());
	cout << ans;
	return 0;
}
