#include <bits/stdc++.h>
using namespace std;
char s[1000010];
int a[1000010];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s);
	int len = strlen(s), tot = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			tot++;
			a[tot] = (s[i] - '0');
		}
	}
	sort(a + 1, a + tot + 1, cmp);
	for (int i = 1; i <= tot; i++) {
		printf("%d", a[i]);
	}
	return 0;
}