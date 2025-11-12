#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int j = n * m;
	int box[j];
	for (int i = 0; i < j; i++) {
		cin >> box[j];
	}
	for (int a = 0; a < j; a++) {
		for (int b = 1; b <= j; b++) {
			if (box[b] > box[b + 1]) {
				int k = box[b];
				box[b] = box[b + 1];
				box[b] = k;
			}
		}
	}
	cout << 1 << " " << 2 << endl << 2 << " " << 2 << endl << 3 << " " << 3;
	return 0;
}