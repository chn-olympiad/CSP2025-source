#include <bits/stdc++.h>
using namespace std;
char a[1000005];
int b[15];

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> a;
	for (int i = 0; a[i] != 0; i++) {
		if (('0' <= a[i]) && (a[i] <= '9'))
			b[a[i] - '0']++;
	}
	for (int i = 9; i >= 0; i--) {
		if (b[i] != 0) {
			for (int j = 1; j <= b[i]; j++)
				cout << i;
		}
	}
	return 0;
}
