#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	int nm;
	int cr;
	int sum = 0;
	cin >> n >> m;
	cin >> cr;
	cin >> nm;
	for (int i = 1; i <= nm; i++) {
		sum += cr;
	}
	cout << cr << endl;
	return 0;
}
