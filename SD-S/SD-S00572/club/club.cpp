#include <bits/stdc++.h>
#define Pii pair <int, int>
using namespace std;
const int N = 2e5 + 20;
priority_queue <int, vector <int>, greater <int> > q[3];
int a[N][3], n;
int Min (int x, int y, int z) {
	return min (min (x, y), z);
}
int Max (int x, int y, int z) {
	return max (max (x, y), z);
}
int Mid (int x, int y, int z) {
	return x + y + z - Min (x, y, z) - Max (x, y, z);
}
int sum = 0;
void work() {
	sum = 0;
	for (int i = 0; i < 3; i++) {
		while (q[i].size()) q[i].pop();
	}
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			scanf ("%d", &a[i][j]);
		}
		int mxx = Max (a[i][0], a[i][1], a[i][2]);
		int mid = Mid (a[i][0], a[i][1], a[i][2]);
		int h = 0;
		for (int j = 0; j < 3; j++) {
			if (a[i][j] == mxx) {
				h = j;
				break;
			}
		}
		q[h].push(mxx - mid);
		sum += mxx;
	}
	for (int i = 0; i < 3; i++) {
		while (q[i].size() > n / 2) {
			sum -= q[i].top();
			q[i].pop();
		}
	}
	printf ("%d\n", sum);
}
int main() {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	int T;
	scanf ("%d", &T);
	while (T--) {
		work();
	}
	return 0;
}
