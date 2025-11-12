#include <bits/stdc++.h>
using namespace std;

const int MAX_NM = 10;

int n, m;
int arr[MAX_NM * MAX_NM + 1];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; ++i) scanf("%d", arr + i);
	int val = arr[1];
	sort(arr + 1, arr + 1 + n * m, greater<int>());
	int pos = lower_bound(arr + 1, arr + 1 + n * m, val, greater<int>()) - arr;
	// printf("%d ", pos);
	int col = (pos + n - 1) / n;
	int row = col & 1 ? pos % n : n - pos % n + 1;
	if (pos % n == 0) row = n;
	printf("%d %d", col, row);
	return 0;
}
