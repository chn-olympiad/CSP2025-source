#include <bits/stdc++.h>
using namespace std;
int a[11] = {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0};
int main() {
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++) {
		char c = s[i];
		if(c >= '0' and c <= '9')
			a[c - '0']++;
	}
	for(int i = 9; i >= 0; i--) {
		while(a[i]--)cout << i;
	}
	return 0;
}
