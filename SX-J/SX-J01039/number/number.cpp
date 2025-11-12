#include <bits/stdc++.h>
using namespace std;
string s;
int a[100005];
int o = 1;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') {
			o += 1;
			a[o] = 0;
		} else if (s[i] == '1') {
			o += 1;
			a[o] = 1;
		} else if (s[i] == '2') {
			o += 1;
			a[o] = 2;
		} else if (s[i] == '3') {
			o += 1;
			a[o] = 3;
		} else if (s[i] == '4') {
			o += 1;
			a[o] = 4;
		} else if (s[i] == '5') {
			o += 1;
			a[o] = 5;
		} else if (s[i] == '6') {
			o += 1;
			a[o] = 6;
		} else if (s[i] == '7') {
			o += 1;
			a[o] = 7;
		} else if (s[i] == '8') {
			o += 1;
			a[o] = 8;
		} else if (s[i] == '9') {
			o += 1;
			a[o] = 9;
		}
	}
	sort(a + 1, a + o + 1);
	for (int i = o; i >= 2; i--) {
		cout << a[i];
	}
	return 0;
}