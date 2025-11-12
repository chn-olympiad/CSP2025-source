#include <bits/stdc++.h>
using namespace std;

int n, m, a[101], order;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}

	int littleR = a[1];

	sort(a + 1, a + n * m + 1, greater<int>());
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == littleR) {
			order = i;
			break;
		}
	}

	int cnt = 0, i = 1, j = 1, same_direction_cons_walk_cnt = 0;
	bool up = 1;
	for (int k = 1; k < order; k++) {
		if (same_direction_cons_walk_cnt != n - 1) {
			if (up) {
				j++;
			}

			else {
				j--;
			}

			same_direction_cons_walk_cnt++;
		}

		else {
			same_direction_cons_walk_cnt = 0;
			up = (!up);
			i++;
		}
	}

	cout << i << " " << j << endl;
	return 0;
}

/*
It seems today, that all you see,
is violence on movies and s** on TV.
But where are those good old-fashioned values,
on which we used to rely?

Lucky there's a FAMILY GUY!
Lucky there's man who positively can do.
All things make us,
laugh and cry.
HE IS A FAMILY GUY!
*/