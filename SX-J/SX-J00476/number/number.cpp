#include <bits/stdc++.h>
using namespace std;
string s, a;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	long long n;
	for (int i = 0; i <= s.size() - 1; i++) {
		if (s[i] <= '9' && s[i] >= '0') {
			n++;
			a[n] = s[i];
		}
	}

	for (int i = 0; i <= a.size() - 1; i++) {
		for (int j = 0; j <= a.size() - 1; j++) {
			if (a[i] < a[j]) {
				a[i] = a[j];
			}
		}
	}
	for (int i = 0; a.size() - 1; i++) {
		cout << a[i];
	}
	return 0;
}
