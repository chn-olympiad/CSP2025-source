#include <bits/stdc++.h>
using namespace std;
char c;
int a[10];
bool flag = 0;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	while (cin >> c) {
		if (c >= '0' && c <= '9')
			a[c - '0']++;
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= a[i]; j++) {
			flag = flag | (i > 0);
			if (flag)
				cout << i;
		}
	}
	if (flag == 0)
		cout << 0;
	return 0;
}