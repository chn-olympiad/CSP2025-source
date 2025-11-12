#include <bits/stdc++.h>
using namespace std;
char s[1000010];
int a[1000010];

bool cmp(int u, int v) {
	return u > v;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s + 1);
	int len = strlen(s + 1);
	int cnt = 0;
	for (int i = 1; i <= len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[++cnt] = s[i] - '0';
		}
	}
	sort(a + 1, a + 1 + cnt, cmp);
	for (int i = 1; i <= cnt; i++)
		printf("%d", a[i]);
	return 0;
}
