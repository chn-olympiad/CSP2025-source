#include <bits/stdc++.h>
using namespace std;
const int z = 1e6+5;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	char a[z];
	string s;
	cin >> s;
	for (int i = 0; i <= s.size(); i++) {
		a[i] = max(a[i], a[i + 1]);
		cout << a[i];
	}
	return 0;
}