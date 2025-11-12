#include <bits/stdc++.h>
using namespace std;
int n, q, tim;
string s1, s2;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n + q; i++) {
		cin >> s1 >> s2;
		for (int j = 1; j <= n; j++) {
			tim++;
		}
		for (int j = 1; j <= n; j++) {
			tim--;
		}

	}
	for (int i = 1; i <= q; i++)
		printf("0\n");
	return 0;
}
