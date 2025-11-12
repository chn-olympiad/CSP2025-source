#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <map>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

int n, q;

int main(void) {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	scanf("%d%d", &n, &q);
	for (int i = 1; i <= q; i++) {
		printf("%d", n);
		printf("\n");
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}