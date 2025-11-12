#include <algorithm>
#include <iostream>

bool f(int a, int b);

int main() {
	freopen("seat.in",  "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m, *grade, a1;
	std::cin >> n >> m;
	grade = (int*)malloc(sizeof(int) * n * m);
	for(int c = 0; c < n*m; c++) {
		std::cin >> grade[c];
	}
	a1 = grade[0];
	std::sort(grade, grade + (n*m), f);
	for(int c = 1; c <= n; c++) {
		if(grade[c*m] >= a1) continue;
		if(c%2) {
			for(int C = 1; C <= m; C++) {
				if(grade[(c-1)*m + C - 1] == a1){
					std::cout << c << ' ' << C;
					break;
				}
			}
		}
		else {
			for(int C = m; C > 0; C--) {
				if(grade[c*m - C] == a1){
					std::cout << c << ' ' << C;
					break;
				}
			}
		}
	}
	return 0x000000;
}

bool f(int a, int b) {
	return a > b;
}
