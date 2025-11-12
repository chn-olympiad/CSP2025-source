#include <bits/stdc++.h>

using namespace std;
#define int long long
string s;
priority_queue<int>p;
int cnt;

signed main() {

	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			int a = s[i] - '0';
			p.push(a);
			cnt++;
		}
	}
	for (int i = 1; i <= cnt; i++) {
		if (i == 1 && p.top() == 0) {
			cout << 0;
			return 0;
		}
		cout << p.top();
		p.pop();
	}

	return 0;
}
