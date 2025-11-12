#include <bits/stdc++.h>
using namespace std;
int b[100000];
int o = -100, l[10000], h[10000];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string a;
	cin >> a;
	if (a.size() == 2 && a[1] <= '9' && a[1] >= '0') {
		cout << a[1];
		return 0;
	}
	if (a.size() == 2 && a[1] <= '9' && a[1] >= '0' && a[2] <= '9' && a[2] >= '0' && a[2] > a[1]) {
		cout << a[2] << a[1];
		return 0;
	}

	int k = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '1' || a[i] == '2' || a[i] == '3' || a[i] == '4' || a[i] == '5' || a[i] == '6' || a[i] == '7'
		        || a[i] == '8' || a[i] == '9' || a[i] == '0' ) {
			k++;
			if (a[i] == '1')
				b[k] = 1;
			if (a[i] == '2')
				b[k] = 2;
			if (a[i] == '3')
				b[k] = 3;
			if (a[i] == '4')
				b[k] = 4;
			if (a[i] == '5')
				b[k] = 5;
			if (a[i] == '6')
				b[k] = 6;
			if (a[i] == '7')
				b[k] = 7;
			if (a[i] == '8')
				b[k] = 8;
			if (a[i] == '9')
				b[k] = 9;
			if (a[i] == '0')
				b[k] = 0;
			cout << b[k];
		}
	}

	return 0;
}
