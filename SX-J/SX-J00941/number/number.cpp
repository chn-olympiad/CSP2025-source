#include <bits/stdc++.h>
using namespace std;
int a[1000010];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int n = s.size(), m = 1;
	for (int i = 0; i < n; i++)
		if (s[i] >= '0' && s[i] <= '9')
			a[m++] = s[i] - '0';
	sort(a + 1, a + m, cmp);
	for (int i = 1; i < m; i++)
		printf("%d", a[i]);
	return 0;
}