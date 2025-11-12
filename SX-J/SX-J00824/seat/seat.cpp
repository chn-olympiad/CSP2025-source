#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
	return a >= b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int a[11][11] = {0}, b[110] = {0};
	int n, m, k, x = 0, y = 0;    //nÁÐmÐÐ
	bool d = true;
	cin >> n >> m;
	for (int i = 0; i < n * m; i++)
		cin >> b[i];
	k = b[n * m - 1];
	//cout << k << endl;
	sort(b, b + n *m, cmp);
	for (int i = 0; i < n * m; i++) {
		a[x][y] = b[i];
		if (d) {
			y += 1;
			if (y == m) {
				x += 1;            //yÐÐ
				d = false;
			}
		} else if (!d) {
			y -= 1;
			if (y == 0) {
				x += 1;
				d = true;
			}
		}
		if (a[i / n][i % m] == k) {
			cout << y + 1 << ' ' << x + 1 << endl;
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
