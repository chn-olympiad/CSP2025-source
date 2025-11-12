#include <bits/stdc++.h>
using namespace std;
char s[1000005];
int a[1000005];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s + 1;
	int len = strlen(s + 1);
	int ans = 0;
	for (int i = 1; i <= len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			ans++;
			a[ans] = s[i] - 48;
		}
	}
	sort(a + 1, a + 1 + ans, greater<int>());
	for (int i = 1; i <= ans; i++) {
		cout << a[i] ;
	}
	return 0;
}