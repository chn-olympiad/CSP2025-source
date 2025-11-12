#include <bits/stdc++.h>
using namespace std;

int s[11][11] = {}, sc[105], n, m;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= m * n; i++)
		cin >> sc[i];
	int ming = sc[1];
	sort(sc + 1, sc + m *n + 1, cmp);
	int j = 1;
	for (int y = 1; y <= n;) {
		for (int x = 1; x <= m;) {
			s[y][x] = sc[j];

			if (sc[j] == ming) {
				cout << x << ' ' << y;
				fclose(stdin);
				fclose(stdout);
				return 0;
			}
			if (x % 2 == 1) {
				if (y != n)
					y++;
				else
					x++;
			} else {
				if (y != 1)
					y--;
				else
					x++;
			}
			j++;

		}
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
