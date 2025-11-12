#include <bits/stdc++.h>
using namespace std;
int n, m;

struct stu {
	int cj = 0;
	int own = 0;
} zuowei[105];

int cmp(stu a, stu b) {
	return a.cj > b.cj;
}
int flag;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> zuowei[i].cj;
	}
	zuowei[1].own = 1;
	sort(zuowei + 1, zuowei + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		//cout << zuowei[i].cj << " ";
		if (zuowei[i].own == 1) {

			flag = i;
		}
	}
	//cout << flag << endl;
	if (flag % n == 0) {
		if ((flag / n) % 2 == 0) {
			cout << flag / n << " " << 1 << endl;
			return 0;
		} else {
			cout << flag / n << " " << n << endl;
			return 0;
		}
	} else if (flag % n != 0) {
		if ((flag / n + 1) % 2 == 0) {
			cout << flag / n + 1 << " ";
			cout << n - (flag % n - 1) << endl;
			//int sum = 1;
			//for (int i = n; i >= 1; i--) {
			//if (sum == flag % n) {
			//cout << i;
			//	return 0;
			//} else
			//	sum++;

		} else {
			cout << flag / n + 1 << " " << flag % n << endl;
		}
	}
	return 0;
}


