#include <bits/stdc++.h>
using namespace std;
int b[1000086];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string a;
	cin >> a;
	int c = 0, d = a.size();
	for (int i = 0; i < d; i++) {
		if (a[i] >= 48 && a[i] <= 58) {
			b[c++] = a[i] - 48;
		}
	}
	sort(b, b + c, cmp);
	for (int i = 0; i < c; i++) {
		cout << b[i];
	}
	return 0;
}
