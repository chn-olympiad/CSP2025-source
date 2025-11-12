#include <bits/stdc++.h>
using namespace std;
string s, r;
long long ans, a[1000100], j;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	getline(cin, s);
	int len = s.size();
	for (int i = 0; i <= len - 1; i++) {
		if (isdigit(s[i])) {
			r = r + s[i];
		}
	}
	sort(r.begin(), r.end(), greater<int>() );
	cout << r;
	return 0;
}
