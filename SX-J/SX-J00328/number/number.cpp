#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int a[N];

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int tot = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9')
			a[++tot] = s[i] - '0';
	}
	sort(a + 1, a + tot + 1, greater<int>());
	for (int i = 1; i <= tot; i++)
		cout << a[i];
	return 0;
}
