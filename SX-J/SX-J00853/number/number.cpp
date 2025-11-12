#include <bits/stdc++.h>
using namespace std;

string s;
int a[1000006], sum, l;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	l = s.size();
	for (int i = 0; i < l; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[i] = s[i] - '0';
			sum++;
		}
	}
	sort(a + 0, a + l);
	if (a[l - 1] != 0) {
		for (int i = l - 1; i >= l - sum; i--) {
			cout << a[i];
		}
	} else
		cout << 0;
	return 0;
}
