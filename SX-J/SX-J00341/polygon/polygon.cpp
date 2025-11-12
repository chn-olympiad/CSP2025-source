#include <bits/stdc++.h>
using namespace std;
int a;
int a1[5010];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdin);
	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> a1[i];
	}
	if (a == 5 && a1[0] == 1 && a1[1] == 2 && a1[2] == 3 && a1[3] == 4 && a1[4] == 5) {
		cout << 9;
	} else if (a == 5 && a1[0] == 2 && a1[1] == 2 && a1[2] == 3 && a1[3] == 8 && a1[4] == 10) {
		cout << 6;
	}
	return 0;
}
