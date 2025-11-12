#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
string s;
const int S = 1e6+5000;
int a[S];

signed main() {

	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	cin >> s;
	int k = s.size();
	int ans = 0;
	for (int i = 0; i <= k ; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[i] = s[i] - '0';
			ans++;
		}
	}
	sort(a, a + S);
	for (int i = S - 1; i >= S - ans; i--) {
		cout << a[i];
	}
	return 0;
}
