#include <bits/stdc++.h>
using namespace std;
int n, m, arr[105], R, p;

struct ANS {
	int hang, lie;
};

bool cmp(int a, int b) {
	return a > b;
}

ANS my_get(int xia) {
	ANS ans;
	ans.lie = (xia - 1) / n + 1;
	if (ans.lie % 2)
		ans.hang = ((xia % n == 0) ? n : xia % n);
	else
		ans.hang = ((xia % n == 0) ? 1 : (n - xia % n + 1));
	return ans;
}

int my_low(int to) {
	int l = 1, r = m * n, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (arr[mid] == to)
			break;
		if (arr[mid] > to)
			l = mid + 1;
		else if (arr[mid] < to)
			r = mid - 1;
	}
	return mid;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> arr[i];
	}
	R = arr[1];
	sort(arr + 1, arr + n *m + 1, cmp);
	p = my_low(R);
	ANS so = my_get(p);
	cout << so.lie << ' ' << so.hang;
	return 0;
}
