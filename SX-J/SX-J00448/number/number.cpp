#include <bits/stdc++.h>
using namespace std;

long long ztn[10] {0};
char value;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	while (cin >> value) {
		if (value >= '0' && value <= '9') {
			ztn[int(value) - 48]++;
		}
	}
	for (int i = 9; i >= 0 ; i--) {
		for (int j = 0; j < ztn[i]; j++) {
			cout << i;
		}
	}
	return 0;
}
