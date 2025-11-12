#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 1e6;

char s[MAX_SIZE];
int cnt[10];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s);
	int len = strlen(s);
	for (int i = 0; i < len; ++i) {
		if (isdigit(s[i])) ++cnt[s[i] - '0'];
	}
	for (int i = 9; i >= 0; --i) {
		while (cnt[i]--) putchar('0' + i);
	}
	return 0;
}
