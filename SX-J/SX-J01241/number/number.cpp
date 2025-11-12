#include <bits/stdc++.h>
using namespace std;
int n, a[10];
string s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	n = size(s);
	for (int i = 0; i < n; i++) {
		if (s[i] >= '0' && s[i] <= '9')
			a[s[i] - 48]++;
	}
	for (int i = 9; i >= 0; i--) {
		for (; a[i]; a[i]--)
			cout << i;
	}
	cout << endl;
	return 0;
}
