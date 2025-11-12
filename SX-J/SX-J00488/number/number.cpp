#include <bits/stdc++.h>
using namespace std;
char s[1000005];
int flag, ans, t[15];

int main() {
	freopen("number.in", "r", std.in);
	freopen("number.out", "w", std.out);
	cin >> s;
	int j = 0;
	while (1) {
		if (s[j] - 'a' >= 0 && s[j] - 'a' <= 25) {
			j++;
			continue;
		} else if (s[j] - '0' <= 9 && s[j] - '0' >= 0) {
			t[s[j] - '0']++;
			j++;
		} else {
			break;
		}
	}
	int v = 1;
	for (int i = 0; i <= 9; i++) {
		while (t[i]--) {
			ans += i * v;
			v = v * 10;
		}
	}
	cout << ans;
	return 0;
}
