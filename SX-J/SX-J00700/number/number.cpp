#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000000];

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int x = 0;
	for (int i = 0; i <= s.size(); i++) {
		if (s[i] == '0')
			a[x++] = 0;
		else if (s[i] == '1')
			a[x++] = 1;
		else if (s[i] == '2')
			a[x++] = 2;
		else if (s[i] == '3')
			a[x++] = 3;
		else if (s[i] == '4')
			a[x++] = 4;
		else if (s[i] == '5')
			a[x++] = 5;
		else if (s[i] == '6')
			a[x++] = 6;
		else if (s[i] == '7')
			a[x++] = 7;
		else if (s[i] == '8')
			a[x++] = 8;
		else if (s[i] == '9')
			a[x++] = 9;
	}
	for (int i = 0; i <= x; i++) {
		for (int j = 0; j <= x; j++) {
			if (a[i] > a[j]) {
				swap(a[i], a[j]);
			}
		}
	}
	for (int i = 0; i < x ; i++) {
		if (a[i] >= 0 && a[i] <= 9)
			cout << a[i];
	}
	return 0;
}
