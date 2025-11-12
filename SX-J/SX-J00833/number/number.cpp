#include <bits/stdc++.h>
using namespace std;
int a[1000001];
int n;
char c;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	while (cin >> c) {
		if ('0' <= c && c <= '9') {
			n++;
			a[n] = c - '0';
		}
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		cout << a[i];
	}
	return 0;
}
