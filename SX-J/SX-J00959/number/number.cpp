#include <bits/stdc++.h>
using namespace std;
char s[1];
long long a[10000000];

short cmp(int a, int b) {
	if (a != b)
		return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	long long j;
	long long len = strlen(s);
	for (int i = 0; i <= len; i++) {

		if (s[0] % 10 >= '0' || s[0] % 10 <= '9') {
			a[i] = j % 10;
		}

		j = j / 10;
	}
	sort(a, a + 1 + len, cmp);

	for (int i = 0; i <= len; i++) {
		cout << a[i];
	}
	return 0;
}
