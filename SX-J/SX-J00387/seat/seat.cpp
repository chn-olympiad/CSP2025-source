#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, m;
int arr[105];
int index, gd;

signed main() {

	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> arr[i];
	}
	gd = arr[1];
	int cnt = n * m;
	sort(arr + 1, arr + 1 + cnt);
	for (int i = 1; i <= cnt; i++) {
		if (arr[i] == gd) {
			index = cnt - i + 1;
			break;
		}
	}
	//cout << index << endl;
	if (index % n == 0) {
		if ((index / n) % 2 == 0)
			cout << index / n << " " << 1;
		else
			cout << index / n << " " << n;
	} else {
		cout << (index / n) + 1 << " ";
		if ((index / n) % 2 == 0)
			cout << index % n;
		else
			cout << n - (index % n) + 1;

	}

	return 0;
}

/*


4 5
18 14 24 30 29 28 27 26 25 23 21 20 16 15 12 13 11 7 4 1


*/
