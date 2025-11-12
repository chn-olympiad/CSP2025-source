#include <bits/stdc++.h>
using namespace std;
int a[1000005];

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	int k = 0;
	getline(cin, s);
	int l = s.size();
	cout << l << endl;
	for (int i = 0; i < l; i++) {
		if (s[i] <= '9' && s[i] >= '0') {
			k++;
			a[k] = s[i] - '0';
		}
	}
	sort(a + 1, a + k + 1);
	for (int i = k; i >= 1; i--) {
		cout << a[i];
	}
	return 0;
}
