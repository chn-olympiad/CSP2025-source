#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
char a[N];
int b[N];
long long len, len1, t, q;

int cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	len = strlen(a);
	t = 0;
	for (int i = 0; i < len; i++) {
		if ( a[i] == '0') {
			b[t] = 0;
			t++;
		} else if ( a[i] == '1') {
			b[t] = 1;
			t++;
		} else if ( a[i] == '2') {
			b[t] = 2;
			t++;
		} else if ( a[i] == '3') {
			b[t] = 3;
			t++;
		} else if ( a[i] == '4') {
			b[t] = 4;
			t++;
		} else if ( a[i] == '5') {
			b[t] = 5;
			t++;
		} else if ( a[i] == '6') {
			b[t] = 6;
			t++;
		} else if ( a[i] == '7') {
			b[t] = 7;
			t++;
		} else if ( a[i] == '8') {
			b[t] = 8;
			t++;
		} else if ( a[i] == '9') {
			b[t] = 9;
			t++;
		}
	}
	sort(b, b + len, cmp);
	for (int i = 0 ; i < t ; i++) {
		cout << b[i];
	}
	return 0;
}
