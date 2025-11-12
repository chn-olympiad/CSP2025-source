#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	int a[10005];
	cin >> s;
	int l = s.size();
	for (int i = 0; i <= l; i++) {
		if (s[i] >= 1 && s[i] <= 9) {
			s[i] = a[i];

		}
		swap(s[i], s[i + 1]);
		cout << s[i];






	}



	return 0;
}
