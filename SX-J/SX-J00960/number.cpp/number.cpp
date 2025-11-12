#include <bits/stdc++.h>
using namespace std;
char a[1000005], b[1000005];

int tong[15] = {0};

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int i, j, n;
	cin.getline(a, 1000005);
	n = strlen(a);
	for (i = 0; i < n; i++) {
		if (a[i] >= 'a' && a[i] <= 'z') {
			b[i] = -1;
			continue;
		} else
			b[i] = a[i];
	}
	for (i = 0; i < n; i++) {
		if (b[i] == -1)
			continue;
		if (b[i] == '0')
			tong[1]++;
		if (b[i] == '1')
			tong[2]++;
		if (b[i] == '2')
			tong[3]++;
		if (b[i] == '3')
			tong[4]++;
		if (b[i] == '4')
			tong[5]++;
		if (b[i] == '5')
			tong[6]++;
		if (b[i] == '6')
			tong[7]++;
		if (b[i] == '7')
			tong[8]++;
		if (b[i] == '8')
			tong[9]++;
		if (b[i] == '9')
			tong[10]++;
	}
	for (int gj = 15; gj >= 1; gj--) {
		if (tong[gj] == 0)
			continue;
		else {
			for (int d = 1; d <= tong[gj]; d++)
				cout << gj - 1;
		}
	}
}
