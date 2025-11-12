#include <bits/stdc++.h>
using namespace std;
int a[1000005];

bool cmp(int x, int y) {
	return x < y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int l;
	int c = 0;
	l = s.size();
	if (l == 1) {
		cout << s[0] - '0';
		return 0;
	} else {
		for (int i = 0; i < l; i++) {
			if (s[i] >= '0' && s[i] <= '9') {
				a[c] = s[i] - '0';
				c++;
			}
		}
		sort(a, a + c, cmp);
		for (int  i = c - 1; i >= 0; i--) {
			cout << a[i];
		}
	}
	return 0;
}
