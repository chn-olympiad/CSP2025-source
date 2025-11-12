#include <bits/stdc++.h>
using namespace std;
int n;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	if (n < 3) {
		cout << 0;
	} else {
		cout << 1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
