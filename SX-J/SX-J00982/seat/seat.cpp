#include <bits/stdc++.h>
using namespace std;
int seats[105];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int total = n * m;
	for (int i = 1; i <= total; i++) {
		cin >> seats[i];
	}
	int s = seats[1];
//	cout << s << endl;
	sort(seats + 1, seats + total + 1, cmp);
//	for (int i = 1; i <= n * m; i++) {
//		cout << seats[i];
//	}
	for (int i = 1; i <= total; i++) {
		if (seats[i] == s) {
			s = i;
//			cout << s << endl;
		}
	}
//	for (int i = 1; i <= n * m; i++) {
//		cout << seats[i];
//	}
	int c = (s - 1) / n + 1;
	int r;
	if (c % 2 == 0) {
		r = n - (s - 1) % n;
	} else {
		r = (s - 1) % n + 1;
	}
	cout << c << ' ' << r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
