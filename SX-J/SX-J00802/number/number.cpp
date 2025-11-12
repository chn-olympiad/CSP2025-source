#include <bits/stdc++.h>
using namespace std;
int a[1000005], b[1000005], c[1000005], sum = 0, num = 0;

int main() {
	//freopen("number.in", "r", stdin);
	//freopen("number.out", "w", stdout);
	string s, m;
	cin >> s;
	for (int i = 1; i <= 1000005; i++) {
		if (s[i] >= '1' && s[i] <= '9') {
			int d = s[i];
			b[d]++;
			sum++;
		}
	}

	while (num != sum) {
		for (int i = 1000005; i >= 0; i--) {
			if (b[i] != 0) {
				for (int j = 1; j <= b[i]; j++) {
					c[num] = i;
					num++;
				}
			}
		}
	}
	for (int i = 1; i <= num - 1; i++) {
		cout << c[i];
	}
	return 0;
}
