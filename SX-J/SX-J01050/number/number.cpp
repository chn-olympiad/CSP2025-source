#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int s[N];

int main () {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int asd = 0;
	string a;
	cin >> a;
	for (int i = 0; i <= a.size() - 1; i++) {
		if (a[i] == '1') {

			asd++;
			s[asd] = 1;
		} else if (a[i] == '2') {

			asd++;
			s[asd] = 2;
		} else if (a[i] == '3') {

			asd++;
			s[asd] = 3;
		} else if (a[i] == '4') {

			asd++;
			s[asd] = 4;
		} else if (a[i] == '5') {

			asd++;
			s[asd] = 5;
		} else if (a[i] == '6') {

			asd++;
			s[asd] = 6;
		} else if (a[i] == '7') {

			asd++;
			s[asd] = 7;
		} else if (a[i] == '8') {

			asd++;
			s[asd] = 8;
		} else if (a[i] == '9') {

			asd++;
			s[asd] = 9;
		} else if (a[i] == '0') {

			asd++;
			s[asd] = 0;
		}
	}
	for (int i = 1; i <= asd; i++) {
		for (int j = 1; j <= asd; j++) {
			if (s[i] > s[j]) {
				swap(s[i], s[j]);
			}
		}
	}
	for (int i = 1; i <= asd; i++) {
		cout << s[i];
	}
	return 0;
}
