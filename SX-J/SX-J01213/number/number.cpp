#include <bits/stdc++.h>
using namespace std;
string a;
int num[11], aa, mmax = -1;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			aa = a[i] - '0';
			num[aa]++;
			if (mmax < aa)
				mmax = aa;
		}
	}
	if (mmax == 0 || mmax == -1) {
		cout << 0;
		return 0;
	} else {
		for (int i = mmax; i >= 0; i--)
			for (int j = 1; j <= num[i]; j++)
				cout << i;
	}
	return 0;
}
