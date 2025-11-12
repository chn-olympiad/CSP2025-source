#include <bits/stdc++.h>
using namespace std;
char ch[1000005];
int a[1000005];

int main() {
	int cnt = 0;
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> (ch + 1);
	int len = strlen(ch + 1);
	for (int i = 1; i <= len; i++) {
		if (ch[i] >= '0' && ch[i] <= '9')
			a[++cnt] = ch[i] - '0';
	}
	sort(a + 1, a + cnt + 1);
	if (a[cnt] == 0) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = cnt; i >= 1; i--) {
		printf("%d", a[i]);
	}
	return 0;
}
