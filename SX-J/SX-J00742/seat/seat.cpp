#include <bits/stdc++.h>
using namespace std;
int n, m, exam[110], xx, yy;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> exam[i];
	}
	int qwe = exam[1];
	sort(exam + 1, exam + n *m, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (exam[i] == qwe) {
			if (i % m == 0)
				xx = i / m ;
			else
				xx = i / m + 1;
			yy = i - xx * m;
		}
	}
	if (xx % 2 == 0)
		yy = n - yy;
	cout << xx << ' ' << yy;
	return 0;
}
//1 4
//2 3
