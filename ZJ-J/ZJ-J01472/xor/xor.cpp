//CCF CSP-J/S 2025 Junior
//xor.cpp

#include <iostream>

int maxium = 0;
bool flag[107][107];

void dfs(int lf, int rt, int s, int n) {
	if (!flag[lf][rt]) {
		if (s >= maxium) maxium = s;
		return;
	} else {
		for (int i = rt + 1; i <= n; ++i) {
			for (int j = i; j <= n; ++j) {
				dfs(i, j, s + 1, n);
			}
		}
	}
	if (s >= maxium) maxium = s;
	return;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
    
    int lst[1007];
    int dp[107][107];
    int n, k;
	
	std::cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		std::cin >> lst[i];
	}
	
	int num = 0;
	int l, r;
	
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			dp[i][j] = 0;
			for (int l = i; l <= j; ++l) {
				dp[i][j] ^= lst[l];
			}
			if (dp[i][j] == k) {
				num++;
				flag[i][j] = 1;
				if (num == 1) {
					l = i;
					r = j;
				}
			}
		}
	}
	
	if (num == 0) std::cout << 0;
	else {
		dfs(l, r, 1, n);
		std::cout << maxium;
	}
	
	return 0;
}

//written by ZJ-J01472
