#include <bits/stdc++.h>
using namespace std;
int n, m, a[10000], b, id,  al = 1, it, ggb, fl = 0, q = 1;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int mn = n * m;
	for (int i = 1; i <= mn; i++) {
		cin >> a[i];
		if (i == 1)
			b = a[1];
	}
	for (int i = mn; i > 0; i--) {
		for (int j = 1; j <= i; j++) {
			if (a[j] < a[j + 1])
				swap(a[j], a[j + 1]);
		}
	}
	for (int i = 1; i <= mn; i++) {
		if (a[i] == b)
			id = i;
	}
	if (id % n == 0) {
		cout << id / n << ' ';
		for (int i = 1; i <= mn; i++) {
			if (i + n > id && ((i / n) + 1 == id / n || i / n == id / n)  && fl == 0) {
				al++;
				ggb = i;
				fl = 1;
			} else if (i + n > id && ((i / n) + 1 == (id / n) || i / n == id / n) )
				al++;
			else
				q++;
		}
		for (int i = ggb; i <= al; i++) {
			if (a[i] == b)
				it = i - q;
		}
		if ((id / n)  % 2 == 0 )
			cout << (n - it) + 1 << endl;
		else
			cout << it << endl;
	}

	else {
		cout << (id / n) + 1 << ' ';
		for (int i = 1; i <= mn; i++) {

			if (((i / n) + 1 == (id / n) + 1 || i / n == (id / n) + 1  ) && fl == 0) {
				al++;
				ggb = i;
				fl = 1;
			} else if (((i / n) + 1 == (id / n) + 1 || i / n == (id / n) + 1) )
				al++;
			else
				q++;
		}

		for (int i = ggb; i <= al; i++) {
			if (a[i] == b)
				it = i - q;
		}
		if (((id / n) + 1)  % 2 == 0)
			cout << (n - it) + 1 << endl;
		else
			cout << it << endl;
	}
	return 0;
}
