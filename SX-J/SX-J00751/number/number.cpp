#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000005], t;

int cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size();
	for (int i = 0; i <= len - 1; i++) {
		if (s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7'
		        || s[i] == '8' || s[i] == '9' || s[i] == '0') {
			a[t] = s[i];
			a[t] -= '0';
			t++;
		}
	}
	sort(a, a + t, cmp);
	for (int i = 0; i < t; i++) {
		cout << a[i];
	}
	return 0;
}
