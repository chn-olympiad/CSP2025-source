#include <bits/stdc++.h>
using namespace std;

int a[10000091], j = 1;
char s[10000091];

int main() {
	freopen("number4.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s + 1);
	for (int i = 1; i <= 1000078; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[j] = s[i] - '0';
			j++;
		}
	}
	sort(a + 1, a + 1 + j);
	if (a[j] == 0) {
		printf("0");
		return 0;
	}
	for (int i = j; i > 1; i--) {
		printf("%d", a[i]);
	}
	return 0;
}