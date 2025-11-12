#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> a;

int cmp(int a, int b) {
	return a > b;
}

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a.push_back((int)(s[i] - '0'));
		}
	}
	sort(a.begin(), a.end(), cmp);
	for (int i = 0; i < a.size(); i++) {
		cout << a[i];
	}
	return 0;
}
