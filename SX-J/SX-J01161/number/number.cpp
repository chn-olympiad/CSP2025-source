#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1000100];

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int ss = s.size();
	int sss = 0;
	for (int i = 0; i <= ss; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[i] = s[i] - '0';
			sss++;
		}
	}
	sort(a, a + ss);
	bool f = 0;
	int count = 0;
	for (int i = ss; i >= 0; i--) {
		if (f == 0 && a[i] == 0) {
			continue;
		} else {
			cout << a[i];
			f = 1;
			count++;
		}
		if (count == sss) {
			break;
		}
	}
	return 0;
}
