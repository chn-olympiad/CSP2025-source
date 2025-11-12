#include <bits/stdc++.h>
using namespace std;
long long cnt;
char c, s1[1000000 + 5];

bool cmp(char x, char y) {
	return x > y;
}

signed main(void) {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	while (cin >> c ) {
		if (c > '9' || c < '0')
			continue;
		else {
			s1[cnt++] = c;
		}
	}
	sort(s1, s1 + cnt - 1, cmp);
	cout << s1;
	return 0;
}
