#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	long long a, s, d[1000000], f, g = 0;
	cin >> a >> s;
	for (int i = 1; i <= a * s; i++) {
		cin >> d[i];
	}
	f = d[1];
	sort(d, d + 10000);
	for (int i = 1; i <= a * s; i++) {
		if (d[i] != f)
			g++;
		else
			break;
	}
	cout << g / a;
	cout << " " << g % a;
	return 0;
}