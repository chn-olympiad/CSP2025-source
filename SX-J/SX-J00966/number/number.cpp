#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
long long q;
string s;
int a[N];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	getline(cin, s);
	for (long long i = 0; i <  s.size() ; i++) {
		if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
			a[q] = s[i] - '0';
			q++;
		}
	}
	sort(a, a + q);
	for (long long i = q - 1; i > -1; i--) {
		cout << a[i];
	}
	return 0;
}


