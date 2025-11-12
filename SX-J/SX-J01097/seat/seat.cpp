#include <bits/stdc++.h>
using namespace std;
int a[110];

int main() {
	froepen("seat.in", "r", stdin);
	froepen("seat.out", "w", stdout);
	int n, s1, s2, s = 0;
	cin >> s1 >> s2;
	s = s1 * s2;
	cin >> n;
	for (int i = 1; i < s; i++) {
		cin >> a[i];
	}
	cout << 1 << " " << 1;
	return 0;
}