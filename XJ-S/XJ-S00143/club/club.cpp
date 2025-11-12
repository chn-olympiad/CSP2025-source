#include <bits/stdc++.h>
using namespace std;

int a[2][3];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	for (; t > 0; t--) {
		int n, m = 0;
		cin >> n;
		if (n == 2) {
			for (int i = 0; i < 2; i++)
				for (int j = 0; j < 3; j++)
					cin >> a[i][j];
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					if (i != j) m = max(m, a[0][i] + a[1][j]);
		}
		cout << m << endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
