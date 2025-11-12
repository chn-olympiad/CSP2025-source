#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+5;
char c[MAXN];
int num[MAXN];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", c);
	int lc = strlen(c);
	int lennum = 0;
	for (int i = 0; i < lc; i++) {
		if (c[i] >= '0' && c[i] <= '9') {
			num[++lennum] = c[i] - '0';
		}
	}
	sort(num + 1, num + lennum + 1);
	for (int i = lennum; i >= 1; i--) {
		printf("%d", num[i]);
	}
	return 0;
}
