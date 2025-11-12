#include <bits/stdc++.h>
using namespace std;
char s[1000001];
int a[1000001];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int n = 0, i = 1, j = 1;
	while (cin >> s[i]) {
		i++;
		n++;
	}
	for (i = 1; i <= n; i++) {
		if (s[i] >= '0' && s[i] <= '9')
			a[j++] = int(s[i] - 48);
	}
	sort(a + 1, a + j + 1);
	for (i = j ; i > 1; i--)
		cout << a[i];
	return 0;
}
