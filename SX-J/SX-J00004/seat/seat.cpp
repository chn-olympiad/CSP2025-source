#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	char arr[100010];
	int n, boxes[1010], count = 0;
	cin >> n;
	for (int i = 0; i < 1010; i++) {
		boxes[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] - '0' < 10) {
			boxes[i] = arr[i] - '0';
		}
	}
	for (int i = 0; i < 1010; i++) {
		if (boxes[i] > 0) {
			count++;
		}
	}
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < 1009; j++) {
			if (boxes[j] < boxes[j + 1]) {
				int text = boxes[j];
				boxes[j] = boxes[j + 1];
				boxes[j + 1] = text;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << boxes[i];
	}
	return 0;
}
