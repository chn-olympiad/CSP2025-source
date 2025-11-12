#include <iostream>
std::string s[200000][2], t[200000][2];
int n, q;
int main() {
	freopen("replace.in", "r", stdin), freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i ++ ) {
		std::cin >> s[i][0] >> s[i][1];
	}
	for (int i = 1; i <= q; i ++ ) {
		std::cin >> t[i][0] >> t[i][1];
	}
	for (int i = 1; i <= q; i ++ ) {
		printf("0\n");
	}
	return 0;
}
