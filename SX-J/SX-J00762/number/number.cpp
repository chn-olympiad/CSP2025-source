#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+7;
string s;
long long l;
long long a[N], num;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	l = s.size();
	for (int i = 0; i < l; i++) {
		if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
			a[i] = s[i] - '0';
			num++;
		}
	}
	sort(a, a + l );
	for (int i = l - 1; i >= l - num; i--) {
		cout << a[i];
	}
	return 0;
}
