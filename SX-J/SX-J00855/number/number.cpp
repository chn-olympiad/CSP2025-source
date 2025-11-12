#include <bits/stdc++.h>
using namespace std;
int t[15];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", " w", stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			t[s[i] - '0']++;
		}
	}
	for (int i = 10; i >= 0; i--) {
		int e = 0;
		while (e != t[i]) {
			cout << i;
			e++;
		}
	}
	return 0;
}
