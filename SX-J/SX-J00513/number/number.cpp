#include <bits/stdc++.h>
using namespace std;
string s;
int a[15], x;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[s[i] - '0']++;
			x++;
		}
	}
	if (x == a[0])
		cout << 0;
	else {
		for (int i = 9; i >= 0; i--) {
			while (a[i]--) {
				printf("%d", i);
			}
		}
	}
	return 0;
}
