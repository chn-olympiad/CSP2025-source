#include <bits/stdc++.h>
using namespace std;

int main() {
	froepen("number.in", "r", stdin);
	froepen("number.out", "w", stdout);
	string s;
	cin >> s;
	int k = s.size();
	int x[k + 5], sum = 0;
	for (int i = 0; i < s.size(); i++) {

		s[i] = s[i] - '0';
		if (s[i] == 0 || s[i] == 1 || s[i] == 2 || s[i] == 3 || s[i] == 4 || s[i] == 5 || s[i] == 6
		        || s[i] == 7 || s[i] == 8 || s[i] == 9) {
			x[i] = s[i];
			if (x[i] == 0) {
				sum++;
			}
		}
	}
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < s.size() - i - 1; j++) {
			if (x[j] < x[j + 1]) {
				swap(x[j], x[j + 1]);
			}
		}
	}
	for (int i = 0; i < s.size(); i++) {
		if (x[i] != 0) {
			cout << x[i];
		}
	}
	for (int j = 0; j < sum; j++) {
		cout << 0;
	}
	return 0;
}