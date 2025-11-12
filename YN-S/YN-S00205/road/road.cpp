#include <bits/stdc++.h>
using namespace std;

int t, n;
int a[100003][3], m = 0;



int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	cin >> t;
	for (int l = 0; l < t; l++) {
		m = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &a[i][0], &a[i][1], &[i][2]);
		}
		m = max(max(max(a[0][0] + a[1][1], a[0][0] + a[1][2]), max(a[0][1] + a[1][0], a[0][1] + a[1][2])),
		        max(a[0][2] + a[1][0], a[0][2] + a[1][1]));
		cout << m << endl;
	}




	fclose(stdin);
	fclose(stdout);
	return 0;
}