#include <bits/stdc++.h>
using namespace std;
int a[3][100001];
int use[100001];

struct li {
	int z, x;
	bool operator <(li a2) const {
		return z < a2.z;
	}
};
priority_queue<li>A;
priority_queue<li>B;
priority_queue<li>C;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);

	while (t--) {
		int n, ans = 0;
		scanf("%d", &n);
		int y = n / 2;
		int u, o, p;
		u = o = p = y;

		for (int i = 1; i <= n; i++) {

			for (int j = 1; j <= 3; j++) {

				scanf("%d", &a[i][j]);
			}

			int m = min(a[i][3], min(a[i][1], a[i][2]));
			A.push({a[i][1] - m, i});
			B.push({a[i][2] - m, i});
			C.push({a[i][3] - m, i});
		}

		//cout << B.top().z << endl;

		for (int i = 1; i <= n; i++) {

			int g, h, j;

			while (!A.empty() && use[A.top().x]) {
				A.pop();
			}

			if (A.empty() || u <= 0) {
				g = -1e9;
			} else {
				g = A.top().z;
			}

			while (!B.empty() && use[B.top().x]) {
				B.pop();
			}

			if (B.empty() || o <= 0) {
				h = -1e9;
			} else {
				h = B.top().z;
			}

			while (!C.empty() && use[C.top().x]) {
				C.pop();
			}

			if (C.empty() || p <= 0) {
				j = -1e9;
			} else {
				j = C.top().z;
			}

			//cout << g << " " << h << " " << j << " ";

			if (g >= max(h, j)) {
				ans += a[A.top().x][1];
				use[A.top().x] = true;
				A.pop();
				u--;
			} else if (h >= max(g, j)) {
				ans += a[B.top().x][2];
				use[B.top().x] = true;
				B.pop();
				o--;
			} else if (j >= max(g, h)) {
				ans += a[C.top().x][3];
				use[C.top().x] = true;
				C.pop();
				p--;
			}

			//cout << u << " " << o << " " << p << endl;
		}

		printf("%d\n", ans);
	}

	return 0;
}
