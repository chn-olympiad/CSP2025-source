#include <bits/stdc++.h>
#define vi vector<int>
#define pb push_back
using namespace std;
vi a;

bool cmp(int a, int b) {
	return a > b;
}

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	for (int i = 0; i  < s.size(); i ++) {
		if (int(s[i] - 48) >= 0 && int(s[i] - 48) <= 9) {
			a.pb(int(s[i] - 48));
		}
	}
	sort(a.begin(), a.end(), cmp);
	for (int i = 0; i < a.size(); i ++)
		cout << a[i];
	return 0;
}
