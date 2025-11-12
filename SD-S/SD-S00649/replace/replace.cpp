#include<bits/stdc++.h>
using namespace std;

int n, m;
char a[1011][2011], b[1011][2011], l[1011];

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf ("%s%s", a[i], b[i]);
		l[i] = strlen(a[i]);
	}
	for (int i = 1; i <= m; i++) {
		char qa[1011], qb[1011];
		scanf ("%s%s", qa, qb);
		int lq = strlen(qa), ans = 0;
		for (int j = 0; j < lq; j++)
			for (int k = j + 1; k <= lq; k++) {
				bool flag = 1;
				for (int z = 0; z < j; z++)
					if (qa[z] != qb[z]) {
						flag = 0;
						break;
					}
				if (flag == 0)
					continue;
				flag = 1;
				for (int z = k; z < lq; z++)
					if (qa[z] != qb[z]) {
						flag = 0;
						break;
					}
				if (flag == 0)
					continue;
				int lz = k - j;
				for (int z = 1; z <= n; z++) {
					if (lz != l[z])
						continue;
					flag = 1;
					for (int y = 0; y < lz; y++)
						if (a[z][y] != qa[j + y]) {
							flag = 0;
							break;
						}
					if (flag == 0)
						continue;
					flag = 1;
					for (int y = 0; y < lz; y++)
						if (b[z][y] != qb[j + y]) {
							flag = 0;
							break;
						}
					if (flag == 1)
						ans++;
				}
			}
		printf ("%d\n", ans);
	}
	return 0;
}

