#include <bits/stdc++.h>
using namespace std;
int n, m;
int answer1[200];
int seat1[20][20];
int flag = 1;

bool comp(int x, int y) {
	return x > y;
}
int cmp;

int main () {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> answer1[i];
	}
	int db = answer1[1];
	int size1 = n * m;
	sort(answer1 + 1, answer1 + size1 + 1, comp);
	int xb = 0;
	for (int i = 1; i <= size1; i++) {
		if (answer1[i] == db) {
			xb = i;
		}
	}
	for (int i = 1; i <= n; i++) {
		flag = i % 2;
		if (flag == 1) {
			for (int j = 1; j <= m; j++) {
				cmp++;
				if (cmp == xb) {
					cout << i << " " << j;
				}
			}
		} else {
			for (int j = m; j >= 1; j--) {
				cmp++;
				if (cmp == xb) {
					cout << i << " " << j;
				}
			}
		}
	}
	return 0;
}
