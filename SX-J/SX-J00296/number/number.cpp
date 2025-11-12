#include <bits/stdc++.h>
using namespace std;
char s[1000005];
int a[1000005];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	memset(a, 0, sizeof(a));
	int ans = 0;
	cin >> s;
	int len = strlen(s);
	for (int i = 0; i <= len - 1; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[ans] = int(s[i]) - 48;
			ans++;
		}
	}
	sort(a, a + ans);
	for (int i = ans - 1; i >= 0; i--) {
		cout << a[i];
	}
	return 0;
}