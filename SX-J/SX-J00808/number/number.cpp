#include <bits/stdc++.h>
using namespace std;
string s;
int k = 1, a[1000010], l = 0;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++  ) {
		if (s[i] <= '9' && s[i] >= '0') {
			a[k] = s[i] - '0';
			k++;
		}
	}
	sort(a + 1, a + k);
	for (int i = k - 1 ; i >= 1; i--) {
		cout << a[i];
	}
	return 0;
}
