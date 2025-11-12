#include <bits/stdc++.h>
int num[10], n;
char s[1000001];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; i++)
		if (s[i] - '0' < 10)
			num[s[i] - '0']++;
	for (int i = 9; i >= 0; i--)
		for (int j = 0; j < num[i]; j++)
			printf("%d", i);
}