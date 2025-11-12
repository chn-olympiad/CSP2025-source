#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.ans", "w", stdout);
	string s;
	cin >> s;
	int n = s.size();
	int num[n];
	for (int i = 0; i < n; i++) {
		num[i] = -1;
	}
	for (int i = 0; i < n; i++) {
		if (s[i] >= 48 and s[i] <= 57) {
			num[i] = s[i] - '0';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (num[j] < num[j + 1]) {
				swap(num[j], num[j + 1]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (num[i] == -1) {
			return 0;
		} else {
			cout << num[i];
		}

	}
	return 0;
}
