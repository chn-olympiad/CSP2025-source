#include <bits/stdc++.h>
using namespace std;
int a[1000005];
string s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int cnt = 0, n = s.size();
	for (int i = 0; i < n; i++) {
		if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
			a[cnt] = s[i] - '0', cnt++;
		}
	}
	int j =  cnt - 1;
	sort(a, a + cnt);
	for (int i = j; i >= 0; i--) {
		printf("%d", a[i]);
	}
	return 0;
}
