#include <bits/stdc++.h>
using namespace std;
int a[1000];

short cmp(int a, int b) {
	if (a != b)
		return a > b;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	long long c, r, e, f, g;
	cin >> c;
	for (int i = 1; i <= c ; i++) {
		cin >> a[i];
		f++;
	}

	cout << f;
	return 0;
}