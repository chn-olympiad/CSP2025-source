#include <bits/stdc++.h>
using namespace std;

struct w1 {
	int x1, y1;
	int x2, y2;
	int x3, y3;
} q[30005];

bool cmp1(w1 a, w1 b) {
	return a.x1 > b.x1;
}

int k1, k2, k3;
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int q1;
	long long num = 0;
	cin >> q1;
	while (q1--) {
		int n;
		num = 0;
		k1 = k2 = k3 = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int z1, z2, z3;
			cin >> z1 >> z2 >> z3;
			q[i].x1 = z1, q[i].x2 = z2, q[i].x3 = z3;
			q[i].y1 = 0, q[i].y2 = 0, q[i].y3 = 0;
		}
		sort(q + 1, q + 1 + n, cmp1);
		for (int i = 1; i <= n; i++) {
			if (q[i].x1 == max(max(q[i].x1, q[i].x2), q[i].x3) && (q[i].y1 <= n / 2)) {
				num += q[i].x1;
				q[i].y1++;
			} else if (q[i].x2 == max(q[i].x2, q[i].x3) && (q[i].y2  <= n / 2)) {
				num += q[i].x2;
				q[i].y2++;
			} else if (q[1].y3 <= n / 2) {
				num += q[i].x3;
				q[i].y3++;
			}
		}
		cout << num << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}