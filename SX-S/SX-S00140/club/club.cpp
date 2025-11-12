#include <bits/stdc++.h>
using namespace std;
int t = 1000, n = 0;
int a[100005][5];
bool l[100005];
int d[1005];
bool dl = 1;

bool check(int i) {
	if (a[i][1] == 0 && a[i][2] == 0) {
		return 1;
	}
	if (a[i][1] == 0 && a[i][3] == 0) {
		return 1;
	}
	if (a[i][3] == 0 && a[i][2] == 0) {
		return 1;
	}
	return 0;
}

int max_l(int i) {
	if (a[i][1] > a[i][2] && a[i][1] > a[i][3]) {
		return 1;
	}
	if (a[i][2] > a[i][3] && a[i][2] > a[i][1]) {
		return 2;
	}
	return 3;
}

int smax(int i, int m) {

}

void dpl(int x) {
	int sum = 0;
	for (int i = 1000; i > -1; i--) {
		if (d[i] > 0) {
			if (d[i] >= x) {
				sum = sum + x * i;
				cout << sum ;
				i = -2;
			}
			sum += d[i] * i;
			x -= d[i];
			cout << "22z" << sum << endl << x << "hd29";
		}
	}
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for (; t > 0; t--) {
		int s[5] = {0, 0, 0, 0, 0};
		for (int i = 0; i < n; i++) {
			a[i][1] = 0;
			a[i][2] = 0;
			a[i][3] = 0;
		}
		cin >> n;
		int x[5] ;
		x[1] = 0;
		x[2] = 0;
		x[3] = 0;
		memset(l, false, sizeof(l));
		for (int i = 0; i < n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (a[i][2] > 0 || a[i][3] > 0)
				dl = 0;
			d[a[i][1]]++;
			if (check(i)) {
				l[i] = 1;
			}
		}
		if (dl) {
			dpl(x[1]);
		} else {
			for (int i = 0; i < n; i++) {
				int z = max_l(i);
				if (x[z] > 0) {
					s[z] += a[i][z];
					x[z]--;
				} else {

				}
			}
		}
		cout << x[1] + x[2] + x[3] << endl;
	}
	return 0;
}
