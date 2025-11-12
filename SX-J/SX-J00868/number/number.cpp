#include <bits/stdc++.h>
using namespace std;

char s[1000010];

int main() {
	freopen("number1.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s + 1);
	int l = strlen(s + 1);
	for (int i = 1; i <= l; i++) {
		if ((s[i] - '0' < 0) || (s[i] - '0' > 9))
			s[i] = 'a';
	}
	sort(s + 1, s + l + 1);
	for (int i = l; i >= 1; i--)
		if (s[i] != 'a')
			printf("%d", s[i] - 48);
	return 0;
}
