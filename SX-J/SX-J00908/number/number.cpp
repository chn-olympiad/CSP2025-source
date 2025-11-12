#include <bits/stdc++.h>
using namespace std;
int a[1000005];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int j = 0;
	for (int i = 0; i <= s.size() - 1; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[j] = (s[i] - '0');
			j++;
		}
	}
	sort(a, a + j);
	bool f = 0;
	for (int i = j - 1; i >= 0; i--) {
		if (a[i] != 0)
			f = 1;
		if (f)
			cout << a[i];
	}
	return 0;
}
