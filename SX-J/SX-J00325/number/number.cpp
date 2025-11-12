#include <bits/stdc++.h>
using namespace std;
string a;
int c[1000001];
int b;
int y = 0;
int o = 0;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	b = a.length();
	for (int i = 0; i < b; i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			c[o] = int(a[i]) - 48;
			y++;
			o++;
		}
	}
	sort(c, c + y);
	for (int i = y - 1; i >= 0; i--) {
		cout << c[i];
	}
}
