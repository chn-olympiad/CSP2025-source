#include <bits/stdc++.h>
using namespace std ;
bool cmp(int a, int b) {
	return a > b ;
}
long long a[100000000] ;
int main(){
	freopen("number.in", "r", stdin) ;
	freopen("number.out", "w", stdout) ;
	string s ;
	cin >> s ;
	int x = 0 ;
	for (int i = 0 ; i < s.size() ; i ++) {
		if (int(s[i]) >= 48 && int(s[i]) <= 57) {
			a[x] = int(s[i]) - 48 ;
			x += 1 ;
		}
	}
	sort(a, a + x, cmp) ;
	for (int i = 0 ; i < x ; i ++) {
		cout << a[i] ;
	}
	
	return 0 ;
}

