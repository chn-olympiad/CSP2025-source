#include <bits/stdc++.h>
using namespace std;
char s[1000010];
int a[1000010];
int l, x, m = INT_MIN, t;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	l = strlen(s);
	for (int i = 0; i < l; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[i] = s[i] - '0';
			x++;
		}
	}
	for (int i = 0; i < l; i++) {
		for (int i = 0; i <= l; i++) {
			if (a[i] < a[i + 1]) {
				t = a[i];
				a[i] = a[i + 1];
				a[i + 1] = t;
				t = 0;
			}
		}
	}
	for (int i = 0; i < x; i++) {
		{
			cout << a[i];
		}
	}
	return 0;
}