#include <bits/stdc++.h>
using namespace std;
int s[12], n;
char a[1000006];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	int lena = strlen(a);
	for (int i = 0; i < lena; i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			n = a[i] - '0';
			s[n]++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= s[i]; j++) {
			cout << i;
		}
	}
}
