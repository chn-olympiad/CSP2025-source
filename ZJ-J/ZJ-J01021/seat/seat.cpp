#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> temp(n * m);
	const int p = n * m;
	for (int i = 0; i < p; i += 1) {
		cin >> temp[i];
	}
	const int target = temp[0]; 
	sort(temp.begin(), temp.end(), [](int a, int b) -> bool {
		return a > b;
	});
	int count = 1;
	int x = 1, y = 1, ym = 1;
	while (count++ <= p) {
		if (temp[count - 2] == target) {
			cout << x << " " << y;
			return 0;
		}
		if (y == n && ym == 1 || y == 1 && ym == -1) {
			ym = -ym;
			x += 1;
		} else {
			y += ym;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
