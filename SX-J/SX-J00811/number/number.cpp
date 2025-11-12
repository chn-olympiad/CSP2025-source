#include <bits/stdc++.h>
using namespace std;
string s, a, z;
int len;
int mi = INT_MAX;

int main() {
	freopen("number.in", "w", stdin);
	freopen("number.out", "s", stdout);
	cin >> s;
	len = s.size();
	for (int i = 0; i < len; i++) {
		if (isdigit(s[i])) {
			a += s[i];
		}
	}
	len = a.size();
	for (int i = 0; i < a.size(); i++) {
		if (a[i] >= a[i + 1]) {
			z += a[i];
		} else {
			a += a[i];
		}
	}
	cout << z;
	return 0;
}