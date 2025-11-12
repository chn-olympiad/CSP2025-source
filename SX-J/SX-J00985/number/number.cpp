#include <bits/stdc++.h>

using namespace std;

char s[1000001];
int a[1000001];

int cmp(int c, int d) {
	return c > d;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	int i, n, m = 0, t;

	cin >> s;
	n = strlen(s);

	for (i = 1; i <= n; i++) {
		t = s[i - 1] - '0';
		if (t <= 9 && t >= 0)
			a[++m] = t;
	}

	sort(a + 1, a + m + 1, cmp);

	for (i = 1; i <= m; i++)
		cout << a[i];

	fclose(stdin);
	fclose(stdout);

	return 0;
}
