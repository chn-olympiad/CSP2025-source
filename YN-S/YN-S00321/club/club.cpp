#include <bits/stdc++.h>

using namespace std;

int main() {
//	freopen("club.in", "r", stdin);
//	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	int n = 0;
	int arr[100000] = {0}, brr[100000] = {0}, crr[100000] = {0};
	int sum = 0;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> arr[j] >> brr[j] >> crr[j];

		}
		for (int k = 0; k < n; k++) {
			for (int l = k + 1; l < n; l++) {
				if (arr[k] < arr[l]) {
					int a = arr[k];
					arr[k] = arr[l];
					arr[l] = a;
				}
				if (brr[k] < brr[l]) {
					int a = brr[k];
					brr[k] = brr[l];
					brr[l] = a;
				}
				if (crr[k] < crr[l]) {
					int a = crr[k];
					crr[k] = crr[l];
					crr[l] = a;
				}
			}
		}
		int b = 0, c = 0, d = 0, e = 0, f = 0, g = 0;
		for (int m = 0; m < n; m++) {
			int l = 0, y = 0;
			if (arr[e] >= brr[f] && b < n / 2 && arr[e] >= crr[g]) {
				sum += arr[e];
				e++;
				b++;
				l++;
			}
			if (l != 0) {
				y++;
			}
			if (brr[f] >= crr[g] && c < n / 2 && brr[f] >= arr[e] && y == 0) {
				sum += brr[f];
				c++;
				f++;
				l++;
			}
			if (l != 0) {
				y++;
			}
			if (crr[g] >= brr[f] && d < n / 2 && crr[g] >= arr[e] && y == 0) {
				sum += crr[g];
				g++;
				d++;
				l++;
			}
			if (l != 0) {
				y++;
			}
			if (b >= n / 2 && brr[f] < arr[e] && crr[g] < arr[e] && y == 0) {
				if (brr[f] > crr[g]) {
					sum += brr[f];
					f++;
					c++;
				} else {
					sum += crr[g];
					g++;
					d++;
				}
			}
			if (l != 0) {
				y++;
			}
			if (c >= n / 2 && arr[e] < brr[f] && crr[g] < brr[f] && y == 0) {
				if (arr[e] > crr[g]) {
					sum += arr[e];
					e++;
					b++;
				} else {
					sum += crr[g];
					g++;
					d++;
				}
			}
			if (d >= n / 2 && brr[f] < crr[g] && arr[e] < crr[g] && y == 0) {
				if (arr[e] > brr[f]) {
					sum += arr[e];
					e++;
					b++;
				} else {
					sum += brr[f];
					c++;
					f++;
				}
			}
		}
		cout << sum << endl;
		sum = 0;
	}

	return 0;
}