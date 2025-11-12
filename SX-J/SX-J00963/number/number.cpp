#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	int a[100009], j = 1;
	for (int i = 0; i <= int (s.size()) - 1; i ++) {
		if (s[i] <= '9' && s[i] >= '0') {
			a[j] = int(s[i]) - 48;

			j++;

		}
	}

	sort(a, a + j );
	if (a[1] == 0) {
		cout << 0;
		return 0;
	}
	for (int i = j - 1 ; i > 0; i--) {
		cout << a[i];
	}
	return 0;
}
