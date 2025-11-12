#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int l = s.size(), a = 0;
	int n[l + 5] = {};
	for (int i = 0; i < l; i++) {
		if (isalpha(s[a]) != 0) s.erase(a, 1);
		else a++;
	}
	l = s.size();
	for (int i = 0; i < l; i++)n[i] = int(s[i]) - 48;
	sort( n, n + l );
	for (int i = l - 1; i > -1; i--)cout << n[i];
	return 0;
}
