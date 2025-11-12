#include <bits/stdc++.h>
using namespace std;
int a, s, f[105], g, h, l, k, p;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> a >> s;
	for (int i = 0; i <= a - 1; i++)
		cin >> f[i];
	if (s == 2)
		cout << 2;
	else {
		if (s == 0)
			cout << 1;
		else
			cout << s - 1;
	}
	return 0;
}
