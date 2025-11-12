#include <bits/stdc++.h>
using namespace std;
int a[19];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		char q;
		q = s[i];
		if (int(q) <= 9 && int(q) >= 0) {
			a[int(q)]++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= a[i]; j++) {
			cout << i;
		}
	}
	return 0;
}
