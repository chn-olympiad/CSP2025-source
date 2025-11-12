#include <bits/stdc++.h>
using namespace std;
string s;
int b, d[100006], f[100006] ;

int pdzs(int a) {
	b = a - 'z';
	if ( b < -64) {
		b += 74;
		return b;
	}
	return 0;
}

int main() {
	//freopen("numebr.in","r",stdin);
	//freopen("numer.out","w",stdout);
	cin >> s;
	int cd = s.size();
	for (int i = 0; i < cd; i++) {
		if (pdzs(s[i]) >= 0) {
			d[i] = pdzs(s[i]);
			cout << d[i];
		}

	}

	return 0;
}