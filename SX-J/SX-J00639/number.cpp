#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int l = strlen(s), b = -1, h = 0;
	for (int i = 0; i < l; i++) {
		if (s[i] <= "9" && s[i] >= "0") {
			b++;
			a[b] = s[i] - "0";
			h++;
		}
	}
	sort(a + 1, a + h + 1);
	for (int i = h - 1; i >= 0; i--) {
		cout << a[i]
	}

	return 0;
}