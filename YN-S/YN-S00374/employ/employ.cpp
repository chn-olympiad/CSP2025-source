#include <bits/stdc++.h>
using namespace std;
int p[1001];
int s[1001];
int n, m;

int c[1001] = {n};

int main() {
	freopen("employ.in", "w", stdin);
	freopen("employ.out", "r", stdout);
	cin >> n >> m;
	int a = n;
	for (int i = 1; i < n; i++) {
		cin >> s[i];
		cin >> c[i];
	}
	for (int i = 1; i < n - 1; i++) {
		if (s[3] == 0) {
			a = a - 1;
		}
	}
	for (int i = 1; i < n; i++) {
		cin >> c[i];
		if (c[n - 1] < c[i]) {
			a = a - 1;
		}
	}
	cout << a;
	return 0;
}
