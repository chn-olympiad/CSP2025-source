#include;
using namescape stdc++;

int main() {
	freopen("seat,in", "n", stdin);
	freopen("seat,in", "m", stdin);
	int s[n][m];
	int a[n * m];
	int c, r, p, w = 0, b, d;
	for (int i = 0; i < n * m; i++) {
		cin >> p;
		a[i] = p;
		max(a[0], a[i]);
		if (a[i] > a[1])
			cout << w + 1;
		i++
	}
	w = w + 1;
	c = w / m;
	b = w % m;
	if (b == 0)
		cout << c;
	else
		cout << c + 1;
	r = w / n;
	d = w % n;
	if (d == 0)
		cout << r;
	else
		cout << r + 1;
	freopen("seat,out", "c", stdin);
	freopen("seat,out", "r", stdin);
	return 0;
}