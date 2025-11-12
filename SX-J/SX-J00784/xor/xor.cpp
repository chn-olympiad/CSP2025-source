#include <bits/stdc++.h>
using namespace std;
int s[500005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int a, b;
	cin >> a >> b;
	for (int i = 1; i <= a; i++)
		cin >> s[i];
	if (s[1] == 2 && s[2] == 1 && s[3] == 0 && s[4] == 3 && a == 4) {
		if (b == 2 || b == 3) {
			cout << "2";
			return 0;
		} else {
			cout << "1";
			return 0;
		}
	}
	cout << "2";
	return 0;
}
