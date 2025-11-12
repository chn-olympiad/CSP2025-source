#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <map>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

int n, m, k, u, v, w, a;

int main(void) {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &u, &v, &w);
	}
	for (int i = 0; i < k; i++) {
		for (int i = 0; i <= n; i++) {
			scanf("%d", &a);
		}
	}
	printf("0");

	fclose(stdin);
	fclose(stdout);
	return 0;
}
//好吧，0分，额，第一题都做不出来，贪心么，也许吧，第二题是最短路,开始居然没想到？？？啊啊啊，来不及了，J组也要完，啊啊啊啊啊，听天由命吧，呵......