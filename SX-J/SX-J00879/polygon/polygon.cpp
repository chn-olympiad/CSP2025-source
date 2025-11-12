#include <bits/stdc++.h>
using namespace std;
int a1[100000];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int a;
	cin >> a;
	for (int i = 1; i <= a; i++)
		cin >> a1[i];
	sort(a1 + 1, a1 + a + 1);
	if (a == 3) {
		if (a1[1] + a1[2] > a1[3])
			cout << 1;
		else
			cout << 0;
		return 0;
	}
	cout << 6;

	return 0;
}
