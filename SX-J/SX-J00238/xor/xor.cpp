#include <bits/stdc++.h>
using namespace std;
int a[25], b[25];
int n, k;

int abc (int x, int y) {
	int maxx = 0;
	int su = 0;
	for (int i = 1; i <= 25; i++) {
		a[i] = b[i] = 0;
	}
	int s = x;
	int cnt = 0;
	int sum = 2;
	while (s) {
		cnt++;
		a[cnt] = s % sum;
		s /= sum;
		sum *= 2;

	}
	maxx = max(cnt, maxx);
	s = y;
	cnt = 0;
	sum = 2;
	while (s) {
		cnt++;
		b[cnt] = s % sum;
		s /= sum;
		sum *= 2;
	}
	maxx = max(cnt, maxx);

	for (int i = 1; i <= maxx; i++) {
		if (a[i] == b[i]) {
			su += 0;
		} else {
			int ss = 1;
			for (int j = 1; j < i; j++) {
				ss *= 2;
			}
			su += ss;
		}
	}
	return su;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {

	}

	return 0;
}

