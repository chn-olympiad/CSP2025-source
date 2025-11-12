#include <bits/stdc++.h>
using namespace std;
string s;
int a[10];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int n = s.length();
	for (int i = 0; i <= 9; i++) {
		a[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		if (s[i] >= 48 && s[i] <= 57) {
			int b = s[i] - 48;
			a[b] += 1;
		}
	}
	for (int i = 9; i >= 0; i--) {
		if (a[i] > 1) {
			for (int j = a[i]; j > 0; j--) {
				cout << i;
				a[i]--;
			}
		} else if (a[i] == 1) {
			cout << i;
			a[i]--;
		}
	}
	return 0;
}
