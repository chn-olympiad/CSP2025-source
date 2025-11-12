#include <bits/stdc++.h>
using namespace std;

int num[1005] ;
string s;

void cmp(int a, int b) {
	int c = a;
	a = b;
	b = c;
}

int main() {
	//freopen(number.in, "r", stdin);
	//freopen(number.out, "w", stdout);
	cin >> s;
	int n = 0;
	for (int i = 0; i < s.length(); i++) {
		//cout << s[i] - '0';
		//if(97)
		if ('1' <= s[i] && s[i] <= '9') {
			num[n] = s[i] - '0';
			n++;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << num[i];
	}
	return 0;
}