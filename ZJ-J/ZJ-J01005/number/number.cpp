#include <bits/stdc++.h>
using namespace std;
string s, ans;
bool cmp(char& a, char& b) {return a > b;}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (char& it : s) {
		if ('0' <= it && it <= '9') ans.push_back(it);
	}
	sort(ans.begin(), ans.end(), cmp);
	cout << ans;
	return 0;
}
