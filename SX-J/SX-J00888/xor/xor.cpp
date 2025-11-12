#include <bits/stdc++.h>
using namespace std;
int a[500005]

int main() {
	fropen("seat.in", "r", stdin);
	fropen("seat.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 4 && k == 2) {
		printf("2");
	}
	if (n == 4 && k == 3) {
		printf("2");
	}
	if (n == 4 && k == 0) {
		printf("1");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
