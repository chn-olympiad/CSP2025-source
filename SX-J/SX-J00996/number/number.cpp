#include <bits/stdc++.h>
using namespace std;
int a[1000005];
string s;

bool cmp(int a, int b) {
	return a > b;
}


int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int ans = 0;
	cin >> s;
	for (int i = 0; i <= s.size(); i++) {

		if (s[i] == '0' ) {

			a[i] = 0;
			ans++;
		}

		if (s[i] == '1' ) {

			a[i] = 1;
			ans++;
		}

		if (s[i] == '2' ) {

			a[i] = 2;
			ans++;
		}

		if (s[i] == '3' ) {
			a[i] = 3;
			ans++;
		}

		if (s[i] == '4' ) {
			a[i] = 4;
			ans++;
		}

		if (s[i] == '5' ) {
			a[i] = 5;
			ans++;
		}

		if (s[i] == '6' ) {
			a[i] = 6;
			ans++;
		}

		if (s[i] == '7' ) {
			a[i] = 7;
			ans++;
		}

		if (s[i] == '8' ) {
			a[i] = 8;
			ans++;
		}

		if (s[i] == '9' ) {
			a[i] = 9;
			ans++;
		}
	}

	sort(a, a  + ans, cmp);
	for (int i = 0; i <= ans - 1; i++) {
		cout << a[i ];
	}
	return 0;
}