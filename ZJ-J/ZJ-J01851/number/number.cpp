#include <bits/stdc++.h>
//#inlcude <bits\stdc++.h>

using namespace std;

string s, t;

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
//	freopen("number.in", "r", stdin);
//	freopen("number.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> s;
	for (int i = 0, l = s.size(); i < l; i ++ )
		if ('0' <= s[i] && s[i] <= '9')
			t += s[i];
	sort(t.begin(), t.end(), [](char x, char y){return x > y;});
	cout << t;
	return 0;
}
//ni bei pian le
