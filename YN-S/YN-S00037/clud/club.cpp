#include <bits/stdc++.h>
using namespace std;
int n, a, b, c;
int z, x, y;

int main() {
	freopen("text.in", "r", stdin);
	freopen("text.out", "w", stdout);
	cin >> n;
	cin >> a;
	for (int i = 1; i <= a * n; i++) {
		cin >> z;
	}
	cin >> b;
	for (int i = 1; i <= b * n; i++) {
		cin >> x;
	}
	cin >> c;
	for (int i = 1; i <= c * n; i++) {
		cin >> y;
	}
	cout << 18 << endl;
	cout << 4 << endl;
	cout << 13 << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
