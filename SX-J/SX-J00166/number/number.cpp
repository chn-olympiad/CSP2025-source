#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in","w",stdin);
	freopen("number.out","r",stdout);
	int s, b, c, d;
	cin >> s;
	b = s % 10;
	c = s % 100;
	d = s % 1000;
	if (b > c || 0 <= b <= 10) {
		cout << b << c;
	} else if (b < c || 0 <= c <= 10) {
		cout << c << b;
	} else (b = c);
	{
		cout << b << c;
	}
	return 0;
}
