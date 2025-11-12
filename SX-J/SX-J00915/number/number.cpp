#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int b = s.size();
	int a[b + 1], n = 0;
	for (int i = 0; i < b; i++) {
		if (int(s[i] ) <= '9' - 48 || int(s[i] ) >= '0' - 48) {
			n++;
			a[i] = s[i] ;
		}
	}
	sort(a, a + n);
	for (int i = n - 1 ; i >= 0; i--) {
		cout << a[i] - 48 << " ";
	}
	return 0;
}