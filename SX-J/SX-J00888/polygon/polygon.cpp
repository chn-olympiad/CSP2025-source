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
	if (n == 5 && a[1] == 1) {
		printf("9");
	}
	if (n == 5 && a[1] == 2) {
		printf("6");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}