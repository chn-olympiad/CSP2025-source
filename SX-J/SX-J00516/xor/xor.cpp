#include <bits/stdc++.h>
using namespace std;
int a[5005];
int c[5005];
int d[5005];

int main() {
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n, ant = 0, b, gd, s = 2;
	cin >> n;
	cin >> b;
	a[1] = b;
	gd = b;
	c[1] = 1;
	d[1] = b;
	for (int i = 2; i <= n; i++) {
		cin >> b;
		d[i] = b;
		ant = b + a[i - 1];
		if (b != gd) {
			ant = b;
			gd = b;
			c[s] = i;
			s++;
		}
		a[i] = ant;


	}
	if (d[3] == d[2]) {
		for (int i = 1; i <= n; i++) {
			if ()
			}
	}

	for (int i = 1; i <= n; i++) {
		cout << a[i];


	}
	cout << endl;
	for (int i = 1; i <= n; i++) {

		cout << c[i];

	}
	return 0;
}