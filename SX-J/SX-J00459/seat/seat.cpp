#include <bits/stdc++.h>
using namespace std;
#define int long long

struct node {
	int val;
	int tt;
	int x, y;
	bool rr = 0;
};
int c, r;
node tet[10100];

bool bmp(node a, node b) {
	return a.val > b.val;
}

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> tet[i].val;
	}
	node R;
	R.val = tet[1].val;
	bool f = 0;
	c = 1;
	r = 1;
	sort(tet + 1, tet + 1 + n *m, bmp);
	for (int i = 1; i <= n * m; i++) {
		tet[i].tt = i;

		if (tet[i].tt % n == 0) {
			if (f == 0) {
				tet[i].x = n;
				tet[i].y = tet[i].tt / n;
				r++;
				c = n;
				f = 1;
				//cout << "next up" << endl;

			} else if (f == 1) {
				tet[i].x = 1;
				tet[i].y = tet[i].tt / n;
				r++;
				c = 1;
				f = 0;
				//cout << "next down " << endl;
			}

		}

		//cout << tet[i].tt << " " << tet[i].val << "-----------" << tet[i].x << " " << tet[i].y << endl;;
		if (f == 0) {
			tet[i].y = r;
			tet[i].x = c;
			c++;
			//	cout << "down" << endl;

		} else {
			tet[i].y = r;
			tet[i].x = c;
			c--;
			//	cout << "up" << endl;
		}
		if (tet[i].val == R.val) {
			R.x  = tet[i].x;
			R.y  = tet[i].y;
			if (R.tt % n == 0) {
				if (R.tt % (n + 1) == 0)
					cout << R.x << " " << R.y - 1;
				else
					cout << R.x - 1 << " " << R.y ;
			} else {
				cout << R.x << " " << R.y;
			}

			break;
		}



	}

	return 0;
}