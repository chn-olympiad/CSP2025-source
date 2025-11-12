#include <bits/stdc++.h>
using namespace std;
char s[114514];
int i, tishen, a[114514];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;

	if (strlen(s) < 2) {
		cout << s;
	} else {
		for (i = 1; i <= strlen(s); i++) {
			if (s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8'
			        || s[i] == '9' || s[i] == '0') {
				s[i] = a[i];
			}
		}
		sort(a + 1, a + i + 1, cmp);
		cout << cmp;
	}
	return 0;
}
/*s[i] == 'a'
			        || s[i] == 'b' || s[i] == 'c' || s[i] == 'd' || s[i] == 'e' || s[i] == 'f' || s[i] == 'g' || s[i] == 'h' || s[i] == 'i'
			        || s[i] == 'j' || s[i] == 'k' || s[i] == 'l' || s[i] == 'm' || s[i] == 'n' || s[i] == 'o' || s[i] == 'p' || s[i] == 'q'
			        || s[i] == 'r' || s[i] == 's' || s[i] == 't' || s[i] == 'u' || s[i] == 'v' || s[i] == 'w' || s[i] == 'x' || s[i] == 'y'
			        || s[i] == 'z'*/














