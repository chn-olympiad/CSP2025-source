#include <bits\stdc++.h>
using namespace std;
string s;
long long i, n, c, s1[1000000];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			s1[i] += s[i] - '0';
			c++;
		}
	}
	sort(s1, s1 + s.size(), greater<int>());
	for (i = 0; i < c; i++)
		cout << s1[i];
	return 0;
}
