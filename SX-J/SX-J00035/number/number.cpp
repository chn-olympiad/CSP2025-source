#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int h[1000010];

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
	int j = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			h[j++] = s[i] - '0';
		}
	}
	sort(h, h + j, cmp);
	for (int i = 0; i < j; i++) {
		cout << h[i];
	}
	return 0;
}
