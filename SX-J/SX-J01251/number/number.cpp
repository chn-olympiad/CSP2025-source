#include <bits/stdc++.h>
using namespace std;
char s[1000001];
int x[11];
bool flag = false;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int k = strlen(s);
	for (int i = 0; i < k; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			int a = s[i] - '0';
			x[a]++;
		}
	}
	for (int i = 9; i > 0; i--) {
		while (x[i]) {
			cout << i;
			x[i]--;
			flag = true;
		}
	}
	while (x[0]) {
		if (flag) {
			cout << 0;
			x[0]--;
		} else {
			cout << 0;
			return 0;
		}
	}
}
