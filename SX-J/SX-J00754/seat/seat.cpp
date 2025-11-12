#include <bits/stdc++.h>
using namespace std;

int cj[200];
int a, b, r;
//int zw[100][100];
int h;
int lll;

bool cmp(int qwer, int asdf) {
	return qwer > asdf;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> a >> b;
	for (int i = 1; i <= a * b; i++) {
		cin >> cj[i];
	}
	r = cj[1];
	sort(cj + 1, cj + a *b + 1, cmp);
	/*	for (int i = 1; i <= a * b; i++) {
			cout << cj[i] << " ";
		}*/
	for (int i = 1; i <= a * b; i++) {
		h++;
		if (r == cj[i]) {
			break;
		}
	}
//	cout << h << endl;
	if (h % a == 0) {
		lll = h / a;
	} else {
		lll = h / a + 1;
	}
	if (h / a % 2 != 0) {
		cout << lll << ' '  ;
		if (h % a == 0)
			cout << a;
		else
			cout << h % a;
	} else {
		cout << lll << " " ;

		if (h % a == 0)
			cout << a - a + 1 ;
		else
			cout << a - h % a + 1;
	}
	return 0;
}
