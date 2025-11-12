#include <bits/stdc++.h>
using namespace std;

int t;
int n;
int x[100001];
int y[100001];
int z[100001];
int xa[100001];
int ya[100001];
int za[100001];
int m;
int ma;
int s;
int b, c;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int q = 0; q < t; q++) {
		s = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> y[i];
			if (y[i] == 0) {
				b++;
			}
		}
		if (b == n) {
			for (int i = 0; i < n; i++) {
				sort(x, x + n);
				for (int j = n; j >= ma; j--) {
					s += x[j];

				}
			}
			cout << s;
			break;
		}
		for (int i = 0; i < n; i++) {
			cin >> z[i];
		}


	}
}



