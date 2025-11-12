#include <bits/stdc++.h>
using namespace std;
string s;
long long a[1000005], cnt = 0;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (char(s[i]) >= '0' && char(s[i]) <= '9') {
			cnt++;
			a[cnt] = int(s[i]);
		}
	}
	sort(a + 1, a + 1 + cnt);
	for (int i = cnt; i >= 1; i--) {
		if (a[i] == 48)
			cout << 0;
		else if (a[i] == 49)
			cout << 1;
		else if (a[i] == 50)
			cout << 2;
		else if (a[i] == 51)
			cout << 3;
		else if (a[i] == 52)
			cout << 4;
		else if (a[i] == 53)
			cout << 5;
		else if (a[i] == 54)
			cout << 6;
		else if (a[i] == 55)
			cout << 7;
		else if (a[i] == 56)
			cout << 8;
		else if (a[i] == 57)
			cout << 9;
	}

	return 0;
}
