#include <bits/stdc++.h>
using namespace std;
int d, m, n = 0;

int main() {

//	freopen("number.in", "r", stdin);
//	freopen("number.out", "w", stdout);
	cin >> m;
	int s[m];
	for (int i = 1; i <= m; i++) {
		cin >> s[i];
		if (s[i + 1] == 0) {
			d = s[i];
		}
		if (s[i] < s[i + 1]) {
			d = s[i + 1] * (i * 10) + s[i] * 1;
		} else
			d = s[i] * (i * 10) + s[i + 1] * 1;
		n = n + d;
	}
	cout << n;





	return 0;
}