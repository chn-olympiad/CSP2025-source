#include <bits/stdc++.h>
using namespace std;

char a[1000005];
char b[1000005];

bool cmp(int x, int y) {
	return x >= y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	for (int i = 0; i < strlen(a); i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			b[i] = a[i];
		}
	}
	sort(b, b + strlen(a), cmp);
	for (int i = 0; i < strlen(b); i++) {
		cout << b[i];
	}
	return 0;
}