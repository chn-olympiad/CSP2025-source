#include <bits/stdc++.h>
using namespace std;
char c[1000005], b = '0';
int a[1000005], t = 1, i = 1;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	while (cin >> c[i]) {
		if (c[i] >= '0' && c[i] <= '9') {
			a[t] = c[i] - '0';
			t++;
		}
		i++;
	}
	sort(a + 1, a + 1 + t, cmp);
	for (int j = 1; j < t; j++) {
		cout << a[j];
	}
	return 0;
}
