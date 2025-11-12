#include <bits/stdc++.h>
using namespace std;

string s;

int a[1000086] = {0};

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 1; i <= s.size(); i++) {
		a[s[i - 1]]++;
	}
	for (int i = 57; i >= 48; i--) {
		for (int j = 1; j <= a[i]; j++) {
			cout << i - 48;
		}
	}
	return 0;
}
