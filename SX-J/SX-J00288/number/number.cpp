#include <bits/stdc++.h>
using namespace std;
string s ;
int a, b[1000005], cnt ;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s ;
	a = s.size();
	for (int i = 0 ; i < a ; i++) {
		int x = s[i] - '0' ;
		if (x >= 0 && x <= 9) {
			cnt++;
			b[cnt] = x ;
		}
	}
	sort(b + 1, b + cnt + 1);
	for (int i = cnt ; i >= 1 ; i--) {
		cout << b[i] ;
	}
	return 0;
}
