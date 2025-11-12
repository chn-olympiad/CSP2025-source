#include <bits/stdc++.h>
using namespace std;
int n, q;
const int maxn = 5e6 + 100;
string s1[maxn], s2[maxn], t1[maxn], t2[maxn];


int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d %d", &n, &q);

	for (int i = 1; i <= n; i++) {

		scanf("%s %s", s1[i], s2[i]);
	}

	for (int i = 1; i <= q; i++) {

		scanf("%s %s", t1[i], t2[i]);
	}

	return 0;
}