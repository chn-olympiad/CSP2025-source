#include <bits/stdc++.h>
using namespace std;
int c[1000005];
char o[1000005];

int main () {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> o;
	int tm = 1;
	int len = strlen(o);
	for (int i = 0; i < len; i++) {
		if (o[i] >= '0' && o[i] <= '9') {
			c[tm] = o[i] - '0';
			tm++;
		}
	}
	sort(c, c + tm, greater());
	for (int i = 0; i < tm - 1; i++) {
		cout << c[i] ;
	}
	return 0;
}