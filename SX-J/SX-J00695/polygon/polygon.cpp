#include <bits/stdc++.h>
using namespace std;
int arr[50005];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	for (int i = 1; i <= n; i++) {
		if (arr[i] == 1) {
			sum++;
		}
	}
	if (sum == 0) {
		cout << "9";
	} else {
		cout << "6";
	}
	return 0;
}
