#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int n = s.size();
	int a[10] = {0};
	for (int i = 0; i < n; i++) {
		if (int(s[i]) - 48 >= 0 && int(s[i]) - 48 <= 9)
			a[int(s[i]) - 48] += 1;
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < a[i]; j++) {
			cout << i;
		}
	}
	return 0;
}
