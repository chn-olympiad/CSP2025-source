#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000000];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int n, t = 0;
	int x;
	cin >> s;
	n = s.size();
	for (int i = 0; i < n; i++) {
		x = s[i] - 48;
		if ( 0 <= x && 9 >= x) {
			a[t++] = x;
		}
	}
	sort(a, a + t + 1);
	for (int i = t; i >= 1; i--) {
		cout << a[i];
	}
	return 0;
}
