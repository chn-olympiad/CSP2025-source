#include <bits/stdc++.h>
using namespace std;

int main() {
	string s, a;
	int n;
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	for (int i = 0; i < s.size(); i++) {
		if (isdigit(s[i])) {
			a = a + s[i];
		}
	}
	for (int i = 0; i < a.size(); i++) {
		if (a[i] < a[i + 1]) {
			n = a[i];
			a[i] = a[i + 1];
			a[i + 1] = n;
		}
	}
	return 0;
}
