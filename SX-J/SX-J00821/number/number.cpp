#include <bits/stdc++.h>
using namespace std;
int n, sum, b ;
string s;

int main() {
//	freopen("number.in", "r", stdin);
//	freopen("number.out", "w", stdout);
	cin >> n;
	int len = s.size();
	for (int i = 1; i <= n; i++) {
		cin >> s[i] ;
	}
	cin >> sum;
	for (int i = 1; i < len - 1; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			s[i] += b;
			b += sum;
			break;
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << sum;
	}
	return 0;
}