#include <bits/stdc++.h>
using namespace std;
int a, w;
int sumx, sumy, sumz;

struct node {
	int x, y, z, sum;
} e[100005];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> a;
	for (int i = 1; i <= a; i++) {
		int b;
		cin >> b;
		for (int j = 1; j <= b; j++) {
			cin >> e[j].x >> e[j].y >> e[j].z;
		}
		for (int j = 1; j <= b; j++) {
			if (sumx < b / 2) {
				if (e[j].x >= e[j].y and e[j].x >= e[j].z) {
					e[j].sum = e[j].x;
					sumx++;
				}
			}
			if (sumy < b / 2) {
				if (e[j].y >= e[j].x and e[j].y >= e[j].z) {
					e[j].sum = e[j].y;
					sumy++;
				}
			}
			if (sumz < b / 2) {
				if (e[j].z >= e[j].y and e[j].z >= e[j].x) {
					e[j].sum = e[j].z;
					sumz++;
				}
			}
			w = e[j].sum + w;
		}
		cout << w;
		w = 0;
		for (int j = 1; j <= b; j++) {
			e[j].x = 0;
			e[j].y = 0;
			e[j].z = 0;
		}
		sumx = 0;
		sumy = 0;
		sumz = 0;
	}


	return 0;
}