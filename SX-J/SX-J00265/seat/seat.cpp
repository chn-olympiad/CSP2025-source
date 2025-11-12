#include <bits/stdc++.h>
using namespace std;
int n, m;
int h[110];
int pm = 1;//еецШ
int n1, m1, p;
int a;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> a;
	for (int i = 2; i <= n * m; i ++) {
		cin >> h[i];
		if (h[i] > a) {
			pm ++;
		}
	}
	m1 = (pm - 1) / n + 1; //ап
	n1 = (pm - 1) % n + 1;
	if (m1 % 2 == 0) {
		n1 = n - n1 + 1;
	}
	cout << m1 << ' ' << n1;
	return 0;
}