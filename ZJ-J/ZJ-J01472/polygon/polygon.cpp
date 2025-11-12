//CCF CSP-J/S 2025 Junior
//polygon.cpp

#include <iostream>

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
    
    int n;
    int lst[1007];
    int ans = 0;
    
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
    	std::cin >> lst[i];
	}
	
	if (n == 3) {
		int sm = 0;
		int maxium = 0;
		int maxiumnum;
		for (int i = 1; i <= n; ++i) {
			if (lst[i] >= maxium) {
				maxium = lst[i];
				maxiumnum = i;
			}
		}
		for (int i = 1; i <= n; ++i) {
			if (i != maxiumnum) sm += lst[i];
		}
		if (sm > maxium) ++ans;
	}
	
	std::cout << ans;
	return 0;
}

//written by ZJ-J01472
