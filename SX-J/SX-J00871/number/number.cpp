#include <bits/stdc++.h>
#define int long long
using namespace std;
int h[1000010];

bool cmp(int a, int b) {
	return a > b;
}

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int p = 1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			h[p] = s[i] - '0';
			p++;
		}
	}
	sort(h + 1, h + 1 + p, cmp);
	if (h[1] == 0) {
		cout << '0';
		return 0;
	}
	for (int i = 1; i <  p; i++) {
		cout << h[i];
	}
	return 0;
}