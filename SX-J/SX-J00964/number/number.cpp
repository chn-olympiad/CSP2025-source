#include <bits/stdc++.h>
using namespace std;
string s;
long long a[1000005], l, f;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9')
			a[++l] = s[i] - '0';
	}
	sort(a + 1, a + 1 + l);
	for (int i = l; i >= 1; i--) {
		if (a[i] == 0 && f == 0 && i != 1)
			continue;
		else {
			cout << a[i];
			f = 1;
		}
	}

	return 0;
}
