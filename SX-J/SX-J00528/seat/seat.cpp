#include <bits/stdc++.h>
using namespace std;

bool tfpd(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);


	int n, m, w, al, ah;
	cin >> n >> m;
	int a[100001];
	for (int i = 0; i < n * m; i++) {
		cin >> a[i];
	}
	int xiaoR = a[0];
	for (int i = 0; i < n * m; i++) {
		if (tfpd(a[i], a[i + 1]) == false) {
			swap(a[i], a[i + 1]);
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (a[i] == xiaoR) {
			w = i;
		}
	}
	for (int i = 0; i <= n * m; i++) {
		if (i - 1 == (w * 1.0) / i) {
			al = i;
		}
	}



	cout << al << " " ;
	if ((w + 1) % n == 0) {
		cout << ((w + 1) * 1.0) / n;
	} else {
		cout << (w + 1) % n;
	}


	return 0;
}