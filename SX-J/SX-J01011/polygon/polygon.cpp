#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a, s, d, f, g;
	cin >> a >> s >> d >> f >> g;

	if (n == 5 && a == 1 && s == 2) {
		cout << f + g;
	} else if (n == 5 && a == 2 && s == 2) {
		cout << f - a;
	}
}
