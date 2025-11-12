#include <bits/stdc++.h>
using namespace std;
string s;
char s1[1000005];
long long n, j = 1;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	n = s.size();
	for (long long i = 0; i < n; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			s1[j] = s[i];
			j++;
		}
	}
	sort(s1 + 1, s1 + j + 1);
	for (long long i = j; i > 0; i--) {
		cout << s1[i];
	}
	return 0;
}
