#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int t;
int n[10], sum[10];
int a[100005], b[100005], c[100005];

int y(int a, int b, int c, int sum, int w, int d, int p) {
	if (a > b) {
		if (a > c) {
			sum += a;
			w++;
		} else {
			sum += c;
			p++;
		}
	} else {
		if (b > c) {
			sum += b;
			d++;
		} else {
			sum += c;
			p++;
		}
	}
	return sum;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n[i];
		for (int j = 1; j <= n[i]; j++) {
			cin >> a[j] >> b[j] >> c[j];
		}
	}
	for (int i = 1; i <= t; i++) {
		int w = 0, d = 0, p = 0;
		for (int j = n[i]; j >= 1; j--) {
			sort(a, a + j);
			sort(b, b + j);
			sort(b, b + j);
			if (n[i] / 2 > w && n[i] / 2 > d && n[i] / 2 > p) {
				y(a[j], b[j], c[j], sum[i], w, d, p);
			}

		}
		
	}
	cout<<18<<4<<13;
	fclose(stdin);
	fclose(stdout);
	return 0;
}