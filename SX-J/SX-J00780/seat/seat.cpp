#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[1010];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int x = n * m;
	for (int i = 1; i <= x; i++) {
		cin >> arr[i];
	}
	int bj = arr[1];
	sort(arr + 1, arr + x + 1, cmp);
	for (int i = 1; i <= x; i++) {
		if (arr[i] == bj) {
			bj = i;
			break;
		}
	}
	int lie = ceil(bj * 1.0 / n), yu = bj % n;
	cout << lie << ' ';
	if (yu == 0)
		yu = n;
	if (lie % 2 == 0) {
		yu = n - yu + 1;
	}
	cout << yu;
	return 0;
}