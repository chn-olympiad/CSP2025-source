#include <iostream>
#include <algorithm>
#include <cstring>
#include <string.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	char a[1000005] = {0}, z[1000005] = {0};
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < 1000005; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			cnt++;
			a[cnt] = s[i];

		}
	}
	int maxn = 0, c = 0;
	for (int j = 1; j <= cnt; j++) {
		maxn = 0;
		for (int i = 1; i <= cnt; i++) {
			if (a[i] > maxn) {
				maxn = a[i];
				c = i;
			}
		}
		z[j] = maxn;
		a[c] = '0';
	}
	for (int i = 1; i <= cnt; i++) {
		cout << z[i];
	}

	return 0;
}
