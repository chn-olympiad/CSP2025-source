#include <bits/stdc++.h>
using namespace std;
int n[10];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string a;
	cin >> a;
	int l = a.length();
	for (int i = 0; i < l; i++) {
		if ((a[i] >= '0') && (a[i] <= '9')) {
			int x = a[i] - '0';
			n[x]++;
		}
	}
	for (short i = 9; i >= 0; i--) {
		for (int j = 1; j <= n[i]; j++) {
			cout << i;
		}
	}
	return 0;
}