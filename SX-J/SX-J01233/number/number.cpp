#include <bits/stdc++.h>
using namespace std;
char x;
int num[10];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	while (cin >> x) {
		if (x >= '0' && x <= '9')
			num[x - '0']++;
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = num[i]; j > 0; j--) {
			cout << i;
		}
	}
	return 0;
}
