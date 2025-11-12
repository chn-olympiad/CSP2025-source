#include <bits/stdc++.h>
using namespace std;

char s[1000010];
int ls, a[1000010], t = 0;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in.txt", "r", stdin);
	freopen("number.out.txt", "w", stdout);
	scanf("%s", s + 1);
	ls = strlen(s + 1);
	for (int i = 1; i <= ls; i++) {
		if (s[i] <= 'a')
			a[++t] = s[i] - '0';
	}
	sort(a + 1, a + t + 1, cmp);
	for (int i = 1; i <= t; i++)
		printf("%d", a[i]);
	return 0;
}
