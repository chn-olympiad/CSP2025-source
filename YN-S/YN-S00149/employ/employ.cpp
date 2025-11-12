#include <bits/stdc++.h>
using namespace std;
int h[10005], y = 1;
char c[10005];
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	for (int i = 0; i < n; i++) {
		y = y * h[i];
	}
	cout << y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}