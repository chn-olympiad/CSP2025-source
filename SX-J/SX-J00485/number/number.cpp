#include <bits/stdc++.h>
#include <string>
using namespace std;
string s;
long long a[1500010], num = 0;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[++num] = s[i] - '0';
		}
	}
	sort(a + 1, a + num + 1, greater());
	for (int i = 1 ; i <= num; i++) {
		cout << a[i];
	}
	return 0;
}
