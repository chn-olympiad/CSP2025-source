#include <bits/stdc++.h>
using namespace std;
int a[100000];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int t ;
	for (int i = 0; i < s.size() ; i++) {
		if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
			t ++;
			a[t] = s[i] - '0';
		}
	}
	sort(a + 1, a + 1 + t);
	for (int i = t; i >= 1; i--)
		cout << a[i];
	return 0;

}
