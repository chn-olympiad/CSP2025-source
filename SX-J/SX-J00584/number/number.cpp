#include <bits/stdc++.h>
using namespace std;
int a[1000000];

int main() {
	//freopen("number.in", "r", stdin);
	//freopen("number.out", "w", stdout);
	int b = 0;
	string s;
	int y = 0;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			b++;
			a[b] = s[i] - '0';
			//cout << a[i];
		}
	}
	sort(a, a + b + 1);

	//for (int i = 1; i <= b; i++)
	//	cout << a[i] << "¡¡";
	for (int i = b; i >= 1; i--) {
		if (i != 1 ) {
			y = (y + a[i]) * 10;
		} else
			y = y + a[i];
	}
	cout << y;
	return 0;
}