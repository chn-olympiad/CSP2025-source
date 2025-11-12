#include <bits/stdc++.h>
using namespace std;
int a[110];
int b[110][110];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int nm = n * m;
	for (int i = 1; i <= nm; i++) {
		cin >> a[i];
	}
	int a1 = a[1];
	if (n == 1 && m == 1) {
		cout << "1" << " " << "1";
		return 0;
	}
	for (int i = 1; i <= nm; i++) {
		for (int j = 1; j <= i; j++) {
			if (a[j] < a[j + 1]) {
				swap(a[i], a[i + 1]);
			}
		}
	}
	int iiiiii;
	for (int i = 1; i <= nm; i++) {
		if (a[i] == a1) {
			iiiiii = i;
		}
	}
	if (n == 1) {
		cout << "1 " << a[iiiiii];
		return 0;
	}
	if (m == 1) {
		cout << a[iiiiii] << "1";
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
