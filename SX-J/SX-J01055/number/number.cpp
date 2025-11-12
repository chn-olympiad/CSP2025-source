#include <bits/stdc++.h>
using namespace std;
int a[1000005], x = 1;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[x] = s[i] - '0';
			x++;
		}
	}
	sort(a + 1, a + x);
	for (int i = x - 1; i >= 1; i--) {
		cout << a[i];
	}
	cout << endl;
	return 0;
}