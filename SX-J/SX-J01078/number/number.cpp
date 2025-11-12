#include <bits/stdc++.h>
using namespace std;
int s[100010];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string a;
	int o = 1;
	cin >> a;
	for (int i = 0; i <= a.size() - 1 ; i++) {
		if (a[i]  <= '9' && a[i]  >= '0' ) {
			s[o] = a[i] - '0';
			o++;
		}
	}
	sort(s, s + (o - 1) + 1);
	for (int i = o - 1; i >= 1; i--) {
		cout << s[i];
	}
	return 0;
}