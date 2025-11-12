//CCF CSP-J/S 2025 Junior
//seat.cpp

#include <iostream>
#include <algorithm>

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m;
	int J1_score[117];
	
	std::cin >> n >> m;
	for (int i = 1; i <= n * m; ++i) {
		std::cin >> J1_score[i];
	}
	
	int theCutest = J1_score[1];
	int rk;
	
	std::sort(J1_score + 1, J1_score + n * m + 1);
	
	for (int i = 1; i <= n * m; ++i) {
		if (theCutest == J1_score[i]) rk = n * m - i;
	}
	
	std::cout << rk / m + 1 << " ";
	
	if ((rk / m + 1) % 2 == 0) {
		std::cout << n - rk % m;
	} else {
		std::cout << 1 + rk % m;
	}
	
	return 0;
}

//written by ZJ-J01472
