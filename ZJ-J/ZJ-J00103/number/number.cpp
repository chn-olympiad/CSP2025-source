#include <bits/stdc++.h>

//#define int long long
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))

constexpr int N = 1e6 + 10;
int n, buc[100]; 
char s[N];

int main() {
	freopen("number.in", "r", stdin), freopen("number.out", "w", stdout);
	std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);
	
	std::cin >> (s + 1), n = strlen(s + 1);
	for (int i = 1; i <= n; ++i)
		if ('0' <= s[i] && s[i] <= '9') ++buc[s[i] - '0'];
	for (int i = 9; i >= 0; --i)
		if (buc[i] > 0) {
			for (int j = 1; j <= buc[i]; ++j) std::cout << i;
		}
	
	return 0; 
}

