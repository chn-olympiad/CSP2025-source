#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	vector<int >s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	if (n < 3) {
		cout << 0;
	}
	if (n = 3) {
		if ((max(s[0], max(s[1], s[2])) * 2 ) > (s[0] + s[1] + s[2])) {
			cout << 1;
		} else {
			cout << 0;
		}
	}

	return 0;
}

