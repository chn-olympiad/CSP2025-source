#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	getline(cin, s);
	int j = 0, a[100];
	for (int i = 0; i < s.size(); i++) {
		if (isdigit(s[i])) {
			a[j] = s[i] - '0';
			j++;
		}
	}

	for (int k = 0; k < j; k++) {
		for (int i = 0; i < j - 1; i++) {
			if (a[i] < a[i + 1]) {
				swap(a[i], a[i + 1]);
			}
		}
	}
	for (int i = 0; i < j ; i++) {
		cout << a[i];
	}
	return 0;
}
