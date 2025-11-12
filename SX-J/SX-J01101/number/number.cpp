#include <bits/stdc++.h>
using namespace std;
char s[1000006];
int q[1000006];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	while (scanf(s) != EOF) {
		int len = strlen(s);
		for (int i = 1; i <= len; i++) {
			if (s[i] >= '49' && s[i] <= '57') {
				q[s[i]] = 1;
			}
		}
		for (int i = 1; i <=len; i++) {
			if (q[i] != 0)
				cout << q[i];
		}
	}
	return 0;
}
