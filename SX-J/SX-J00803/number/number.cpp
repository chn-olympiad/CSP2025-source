#include <bits/stdc++.h>
using namespace std;
int s[1830006];
string a;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			s[i] = a[i] - '0' + 1;
		}
	}
	sort(s,  s + a.size());
	for (int i = a.size() - 1; i >= 0; i--) {
		if (s[i] > 0) {
			cout << s[i] - 1;
		}
	}
	return 0;
}
