#include <bits/stdc++.h>
using namespace std;
int arr[100005];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, w, num;
	cin >> n >> m;
	w = n * m;
	for (int i = 1; i <= w; i++)
		cin >> arr[i];
	num = arr[1];
	int sum = 0;
	for (int i = 2; i <= w; i++) {
		if (arr[i] > num) {
			sum++;
		}
	}
	int a = 1, b = 1;
	for (int i = 1; i <= sum; i++) {
		if (a % 2 == 1) {
			if (b == m) {
				a++;
				if (i == sum) {
					break;
				} else {
					b--;
					sum + 1;
				}
			} else {
				b++;
			}
		}
		if (a % 2 == 0) {
			if (b == 1) {
				a++;
				if (i == sum) {
					break;
				} else {
					b++;
					i++;
				}
			} else {
				b--;
			}

		}
	}
	cout << a << " " << b;
	return 0;
}
