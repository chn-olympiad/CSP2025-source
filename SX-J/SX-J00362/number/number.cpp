#include <bits/stdc++.h>
using namespace std;
int a[1000000];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	int  x, cnt = 0;
	cin >> s;
	int l = s.length();
	for (int i = 0; i < l; i++) {
		x = s[i] - '0';
		if (x >= 0 && x <= 9) {
			a[cnt] = x;
			cnt++;
		}
	}
	sort(a, a + cnt);
	for (int j = cnt - 1; j >= 0; j--) {
		cout << a[j];
	}
	return 0;
}
