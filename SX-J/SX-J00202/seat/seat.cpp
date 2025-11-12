#include <bits/stdc++.h>
using namespace std;
int n, m, p, q, c, r;
string s;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> s[m * n];
	q = s[1];
	cout << q;
	for (int i = 1; i <= m * n; i++) {
		if (s[i] >= s[i + 1])
			break;
		else if (s[i] < s[i + 1]) {
			s[i] = p;
			s[i] = s[i + 1];
			s[i + 1] = p;

			cout << 1 << " " << 2 << endl;
			return 0;
		}
	}
}