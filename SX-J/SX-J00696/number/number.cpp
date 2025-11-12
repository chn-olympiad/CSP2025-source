#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

const int N = 1e6+10;
int a[N], x = 1;
string s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (cmp(a[i], a[i + 1])) {
			s = a[i];
		}
	}
	cout << s;
	return 0;
}
