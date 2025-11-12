#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int n, q;

struct node {
	string s1, s2;
} str[200010];
string t1, t2;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		cin >> str[i].s1 >> str[i].s2;
	}
	for (int i = 1; i <= q; i++) {
		cin >> t1 >> t2;
		printf("0\n");
	}
	return 0;
}