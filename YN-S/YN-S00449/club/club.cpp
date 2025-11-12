#include <bits/stdc++.h>
using namespace std;

struct node {
	int a, b, c;
	int maxn;
	int z;

};

bool cmp(node a, node b) {
	return a.maxn > b.maxn;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, n;
	cin >> t;
	int sum = 0;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		node box[1000005] = {};
		for (int i = 1; i <= n; i++) {
			cin >> box[i].a >> box[i].b >> box[i].c;
			box[i].maxn = max(box[i].a, max(box[i].a, box[i].c));
			if (box[i].maxn == box[i].a) {
				box[i].z = 1;
			} else if (box[i].maxn == box[i].b) {
				box[i].z = 2;
			} else if (box[i].maxn == box[i].c) {
				box[i].z = 3;
			}
		}
		sort(box + 1, box + n + 1, cmp);
		int tong[5] = {};
		for (int i = 1; i <= n; i++) {
			sum += box[i].maxn;
			tong[box[i].z]++;
			if (tong[1] > n / 2) {
				tong[1]--;
				sum -= box[i].a;
				int maxb = max(box[i].b, box[i].c);
				if (maxb == box[i].b) {
					tong[2]++;
					sum += box[i].b;
				} else if (maxb == box[i].c) {
					tong[3]++;
					sum += box[i].a;
				}
			} else if (tong[2] > n / 2) {
				tong[2]--;
				sum -= box[i].b;
				int maxb = max(box[i].a, box[i].c);
				if (maxb == box[i].a) {
					sum += box[i].a;
					tong[1]++;
				} else if (maxb == box[i].c) {
					sum += box[i].c;
					tong[3]++;
				}
			} else if (tong[3] > n / 2) {
				tong[3]--;
				sum -= box[i].c;
				int maxb = max(box[i].a, box[i].b);
				if (maxb == box[i].b) {
					sum += box[i].b;
					tong[2]++;
				} else if (maxb == box[i].a) {
					sum += box[i].a;
					tong[1]++;

				}
			}

		}
		cout << sum << endl;

	}
	return 0;
}



