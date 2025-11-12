#include <bits/stdc++.h>
using namespace std;
char a[1000005];
long long b[15];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	int l = strlen(a);
	for (int i = 0; i < l; i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			b[a[i] - '0']++;
		}
	}
	for (int i = l; i >= 0; i--) {
		for (int c = 0; c < b[i]; c++) {
			cout << i;
		}
	}




















	return 0;
}