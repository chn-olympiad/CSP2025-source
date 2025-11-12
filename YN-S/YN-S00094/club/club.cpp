#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

struct node {
	int a, b, c, d;
} f[N];
long long sum = 0, nn[5];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int ne;
	cin >> ne;

	while (ne--) {
		memset(nn, 0, sizeof(nn));
		sum = 0;
		int n;
		cin >> n;

		for (int i = 1; i <= n; i++) {

			cin >> f[i].a >> f[i].b >> f[i].c;

			if (f[i].a > f[i].b && f[i].a > f[i].c && nn[1] != n / 2) {
				f[i].d = 1;
				nn[1]++;
			}

			if (f[i].b > f[i].a && f[i].b > f[i].c && nn[2] != n / 2) {
				f[i].d = 2;
				nn[2]++;
			}

			if (f[i].c > f[i].b && f[i].c > f[i].a && nn[3] != n / 2) {
				f[i].d = 3;
				nn[3]++;
			}
		}

		for (int i = 1; i <= n; i++) {

			if (f[i].d == 1) {
				sum += f[i].a;
			}

			if (f[i].d == 2) {
				sum += f[i].b;
			}

			if (f[i].d == 3) {
				sum += f[i].c;
			}
		}



		cout << sum << endl;

	}

	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/