#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("number.in", "r", stdin);
//	fropen("number.out", "w", stdout);
	int j = 0;
	string s, a, a1;
	cin >> s;
	int b = size(s);
	if (b == 1) {
		cout << s;
	}
	for (int i = 0; i <= b; i++) {
		int k = int(s[i]);
		if (k <= 9) {
			a[j] = k;
			j++;
		}
	}

	return 0;
}