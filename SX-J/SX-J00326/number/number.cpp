#include <bits/stdc++.h>
using namespace std;

int kind[10] = {0};
int al;
string a;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	al = a.size();
	for (int x = 0; x < al; x++) {
		if (a[x] >= '0' && a[x] <= '9')
			kind[a[x] - '0']++;
	}
	for (int x = 9; x >= 0; x--) {
		if (kind[x] == 0)
			continue;
		cout << x;
		kind[x]--;
		if (kind[x] != 0)
			x++;
	}
	return 0;
}
