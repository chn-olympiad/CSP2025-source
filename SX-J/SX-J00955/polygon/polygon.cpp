#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	if (n < 2)
		cout << 0;
	else if (n == 3) {
		int a, s, d;
		cin >> a >> s >> d;
		if (a + s > d && s + d > a && a + d > s)
			cout << 1;
		else
			cout << 0;
	} else {
		int q;
		cout << q;
	}
}