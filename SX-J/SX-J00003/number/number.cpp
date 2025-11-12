#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	getline(cin, s);
	int l = s.size(), a = 0;
	for (int i = 0; i <= l - 1; i++) {
		if (s[i] >= '1' && s[i] <= '9')
			cout << s[i];
	}
	cout << a;
	return 0;
}


