#include <bits/stdc++.h>
using namespace std;
char a[1000010], n[1000010], s;

bool cmp(int a, int b) {
	return a >= b;
}

int main() {
//	freopen("number.in", "r", stdin);
//	freopen("number.out", "w", stdout);
	cin >> a;
	for (int i = 0; i < size(a); i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			n[s] = a[i];
			s++;
		}
	}
	sort(n, n + s + 1, cmp);
	for (int i = 0; i < s; i++) {
		cout << n[i];
	}
	return 0;
}
