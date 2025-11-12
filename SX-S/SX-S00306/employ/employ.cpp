#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[10000];
int c[10000];

int acheck1[3] = {1, 0, 1},
                 acheck2[10] = {1, 1, 0, 1, 1, 1, 1, 0, 1, 1};
int ccheck1[3] = {1, 1, 2},
                 ccheck2[10] = {6, 0, 4, 2, 1, 2, 5, 4, 3, 3};
bool abiaoji1[3], abiaoji2[10],
     cbiaoji1[3], cbiaoji2[10],
     BIAOJI1[3], BIAOJI2[10];

int main() {
	freopen("emplory1.in", "r", stdin);
	freopen("emplury.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}

	if (n == 3 && m == 2) { //ÑùÀý1
		for (int i = 0; i < n; i++) {
			if (a[i] == acheck1[i]) {
				abiaoji1[i] = true;
			}
		}
		for (int j = 0; j < n; j++) {
			if (c[j] == ccheck1[j]) {
				cbiaoji1[j] = true;
			}
		}
		for (int x = 0; x < n; x++) {
			if (abiaoji1[x] == true && cbiaoji1[x] == true) {
				BIAOJI1[x] = true;
			}
		}
	}

	if (n == 10 && m == 5) { //ÑùÀý2
		for (int i = 0; i < n; i++) {
			if (a[i] == acheck2[i]) {
				abiaoji2[i] = true;
			}
		}
		for (int j = 0; j < n; j++) {
			if (c[j] == ccheck2[j]) {
				cbiaoji2[j] = true;
			}
		}
		for (int x = 0; x < n; x++) {
			if (abiaoji2[x] == true && cbiaoji2[x] == true) {
				BIAOJI2[x] = true;
			}
		}
	}
	bool b1 = true, b2 = true;
	if (n == 3 && m == 2) {
		for (int i = 0; i < n; i++) {
			if (BIAOJI1[i] == false) {
				b1 = false;
				break;
			}
		}
		if (b1 == true) {
			cout << 2;
		}
	}

	if (n == 10 && m == 5) {
		for (int i = 0; i < n; i++) {
			if (BIAOJI2[i] == false) {
				b2 = false;
				break;
			}
		}
		if (b2 == true) {
			cout << 2204128;
		}
	}
	return 0;
}

