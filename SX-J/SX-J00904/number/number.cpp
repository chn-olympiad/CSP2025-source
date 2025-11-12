#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	char s[1000000];
	int a[100000], t = 0;
	scanf("%s", s);
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[t] = s[i] - '0';
			++t;
		}
	}
	for (int i = 0; i < t - 1; i++) {
		for (int y = t - 1; y > i; y--) {
			if (a[y] > a[y - 1])
				swap(a[y], a[y - 1]);
		}
	}
	for (int i = 0; i < t; i++) {
		cout << a[i];
	}
	return 0;
}
