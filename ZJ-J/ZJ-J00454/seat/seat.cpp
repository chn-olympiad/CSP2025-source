#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int n, m;
int seat[N];
int R;
bool cmp (int x, int y) {
	return x > y;
}
int main () {
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> seat[i];
	}
	R = seat[1];
	sort (seat + 1, seat + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (seat[i] == R) {
			int X, Y;
			if (i % n != 0) {
				X = i / n + 1;
				Y = ((X % 2 == 1) ? i % n : m - (i % n) + 1);
			} else {
				X = i / n;
				Y = ((X % 2 == 1) ? n : 1);
			}
			cout << X << " " << Y << endl;
			break;
		}
	}
	return 0;
}
