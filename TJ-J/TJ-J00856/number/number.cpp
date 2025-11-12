#include <bits/stdc++.h>

using namespace std;

char s[1000011];
int n;
int a[1000011], cnt = 0;
int c[20];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[++cnt] = s[i] - '0';
		}
	}
	for (int i = 1; i <= cnt; i++) {
		c[a[i]]++;
	}
	for (int i = 9; i >= 0; i--) {
		if (c[i]) {
			for (int j = 1; j <= c[i]; j++)
				printf("%d", i);
		}
	}
	return 0;
}
