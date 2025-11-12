#include <bits/stdc++.h>
using namespace std;
char c[1000005];
int i[1000005];
int f = 0;

bool cmp( int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int n;
	cin >> c;
	n = strlen(c);
	for (int o = 0; o < n; o++) {
		if (c[o] >= 48 && c[o] <= 57) {
			i[f] = c[o] - 48;
			f++;
		}
	}
	sort(i, i + f, cmp);
	if (i[0] == 0)
		cout << 0;
	for (int o = 0; o < f; o++) {
		cout << i[o];
	}
	return 0;
}
