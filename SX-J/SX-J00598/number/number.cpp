#include <bits/stdc++.h>
using namespace std;
int a[1000001];
char s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int tot = 0;
	while (cin >> s) {
		if (s >= '0' && s <= '9') {
			tot++;
			a[tot] = s - 48;
		}
	}
	sort(a + 1, a + tot + 1);
	for (int i = tot; i >= 1; i--) {
		printf("%d", a[i]);
	}
	return 0;
}
