#include <bits/stdc++.h>
using namespace std;
char s[5000005];
long long len, sum = 1, a[5000005], cnt = 0;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	len = strlen(s);
	for (int i = 0; i < len; i++) {
		if (s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7'
		        || s[i] == '8' || s[i] == '9' || s[i] == '0') {
			a[sum] = s[i] - '0';
			sum++;
			cnt++;
		}
	}
	sort(a + 1, a + cnt + 1);
	for (int i = cnt; i >= 1; i--) {
		cout << a[i];
	}
	return 0;
}
