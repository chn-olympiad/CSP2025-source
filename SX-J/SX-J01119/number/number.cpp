#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005], len, num = 1;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	len = s.size();
	for (int i = 0; i <= len - 1; i++) {
		if (s[i] == '0') {
			a[num++] = 0;
		}
		if (s[i] == '1') {
			a[num++] = 1;
		}
		if (s[i] == '2') {
			a[num++] = 2;
		}
		if (s[i] == '3') {
			a[num++] = 3;
		}
		if (s[i] == '4') {
			a[num++] = 4;
		}
		if (s[i] == '5') {
			a[num++] = 5;
		}
		if (s[i] == '6') {
			a[num++] = 6;
		}
		if (s[i] == '7') {
			a[num++] = 7;
		}
		if (s[i] == '8') {
			a[num++] = 8;
		}
		if (s[i] == '9') {
			a[num++] = 9;
		}
	}
	sort(a, a + num);
	for (int i = num - 1; i > 0; i--) {
		cout << a[i];
	}

	return 0;
}