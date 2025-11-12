#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

std::string sq;
int num[1010];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	std::cin >> sq;
	int lo = sq.size();
	int x = 0;
	for (int i = 0; i < lo; i++) {
		if (sq[i] >= '0' && sq[i] <= '9') {
			num[x] = (sq[i] - '0');
			x++;
		}
	}
	std::sort(num + 0, num + x, cmp);
	for (int i = 0; i < x; i++) {
		std::cout << num[i];
	}
	return 0;
}
