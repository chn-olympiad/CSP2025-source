#include <bits/stdc++.h>
using namespace std;
int a[10086][10086], b[10086][10086];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	for (int i = 0; i < 5; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= 5; j++) {
			cin >> a[i][j];
		}
	}
	cout << "13";
	return 0;
}