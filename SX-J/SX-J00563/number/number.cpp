#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in","r","stdin");
	freopen("number.out","w","stdout");
	string s, a;
	cin >> s;
	for (int i = 0; i <= s.size() - 1; i++) {
		if (s[i] - '0' <= 9) {
			a += s[i] ;
		}
	}
	sort(a[0], a + a.size());
	cout << a;
	return 0;
}