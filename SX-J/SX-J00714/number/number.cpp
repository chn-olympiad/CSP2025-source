#include <bits/stdc++.h>
using namespace std;
string s;
long long a[1000005], t;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
			t++;
			a[t] = s[i] - '0';

		}
	}
	sort(a + 1, a + 1 + t);
	for (int i = t; i >= 1; i--)
		cout << a[i];
	return 0;
}
