#include <bits/stdc++.h>
using namespace std;
string s;
long long  a[100100];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	long long  len = s.size();
	long long  num = 0;
	for (int i = 0; i <= len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[num] = s[i] - '0';
			num++;
		}
	}
	sort(a, a + num);
	for (int i = num - 1; i >= 0; i--) {
		cout << a[i];
	}
	return 0;
}
