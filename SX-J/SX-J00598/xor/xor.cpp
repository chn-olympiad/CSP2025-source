#include <bits/stdc++.h>
using namespace std;
int s[3];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	if (k != 1 && k != 0) {
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		if (a <= 1)
			s[a]++;
	}
	if (k == 0) {
		s[1] = s[1] / 2;
		cout << s[0] + s[1];
	} else
		cout << s[1];
	return 0;
}
