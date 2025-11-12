#include <bits/stdc++.h>
using namespace std;
char s[1000005];

int a[1000005] ;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int j = -1;

	cin.getline(s, 1000005);
	int len = strlen(s);
	if (len == 1) {
		cout << s[0];
	} else {
		for (int i = 0; i < len; i++) {
			if (s[i] <= '9' && s[i] >= '0') {
				j++;
				if (s[i] == '0') {
					a[j] = 0;
				} else if (s[i] == '1') {
					a[j] = 1;
				} else if (s[i] == '2') {
					a[j] = 2;
				} else if (s[i] == '3') {
					a[j] = 3;
				} else if (s[i] == '4') {
					a[j] = 4;
				} else if (s[i] == '5') {
					a[j] = 5;
				} else if (s[i] == '6') {
					a[j] = 6;
				} else if (s[i] == '7') {
					a[j] = 7;
				} else if (s[i] == '8') {
					a[j] = 8;
				} else if (s[i] == '9') {
					a[j] = 9;
				}
			}
		}
		for (int i = 0; i < j; i++) {
			sort(a, a + j);
		}
		int sm = 0;
		for (int i = j; i >= -1; i--) {
			sm = sm * 10 + a[i];
		}
		cout << sm;
	}

	return 0;
}
