#include <bits/stdc++.h>
using namespace std;
int n, q, i, j, cnt;
char s1[200002][1000], s2[200002][1000], q1[200002][1000], q2[200002][1000];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (i = 0; i < n; i++)
		scanf("%s%s", &s1[i], &s2[i]);
	for (i = 0; i < q; i++)
		scanf("%s%s", &q1[i], &q2[i]);
	for (i = 0; i < q; i++) {
		cnt = 0;
		for (j = 0; j < n; j++) {
			if (strstr(q1[i], s1[j]) && strstr(q2[i], s2[j]))
				if (strstr(q1[i], s1[j]) == strstr(q2[i], s2[j]))
					cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}