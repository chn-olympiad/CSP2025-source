#include <bits/stdc++.h>

#define F freopen("number.in", "r", stdin);freopen("number.out", "w", stdout)

using namespace std;

int a[15];

int main (void) {
	
	F;
	
	string s;
	int n;
	
	for(int i = 0; i < 10; i++) a[i] = 0;
	
	cin >> s;
	
	n = s.size();
	s = " " + s;
	
	for(int i = 1; i <= n; i++) {
		if(isdigit(s[i])) a[s[i] - '0']++;
	}
	
	for(int i = 9; i >= 0; i--) {
		while(a[i] > 0) cout << i, a[i]--;
	}
	
	return 0;
}
