#include <bits/stdc++.h>
using namespace std;
long long n, t;
long long bj[10], ans;

struct node {
	long long x[10], w, z[10];
} c[1000100];

bool cmp(node a, node b) {
	if (a.w != b.w) {
		return a.w > b.w;
	} else {
		return a.z[2] > b.z[2];
	}

}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%lld", &t);

	while (t--) {
		scanf("%lld", &n);
		ans = 0;

		for (int i = 0; i < 10; i++) {

			bj[i] = 0;
		}

		for (int i = 0; i < n; i++) {

			for (int j = 0; j < 3; j++) {

				c[i].x[j] = j;
				cin >> c[i].z[j];
			}

			for (int j = 0; j < 3; j++) {

				for (int k = j; k < 3; k++) {

					if (c[i].z[j] > c[i].z[k]) {
						swap(c[i].z[j], c[i].z[k]);
						swap(c[i].x[j], c[i].x[k]);
					}
				}
			}

			c[i].w = c[i].z[2] - c[i].z[1];
		}

		sort(c, c + n, cmp);
		int sum = n / 2;


		for (int i = 0; i < n; i++) {

			for (int j = 2; j >= 0; j--) {

				if (bj[c[i].x[j]] < sum) {

					ans += c[i].z[j];
					bj[c[i].x[j]]++;
					break;

				}
			}
		}

		cout << ans << endl;
	}




	return 0;
}
