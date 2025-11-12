#include <bits/stdc++.h>
using namespace std;
char s1[200010][3010];
char s2[200010][3010];
char t1[3010];
char t2[3010];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace,out", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);

	for (int i = 1; i <= n; i++) {

		scanf("%s%s", s1[i], s2[i]);
	}

	while (q--) {
		scanf("%s%s", t1, t2);
		int ans = 0;

		if (strlen(t1) != strlen(t2)) {
			printf("0\n");
			continue;
		}

		for (int i = 1; i <= n; i++) {

			int lens = strlen(s1[i]);
			int lent = strlen(t1);

			if (lens > lent)
				continue;

			for (int j = 0; j < lent; j++) {

				bool ok = true;

				for (int k = 0; k + j < lent; k++) {

					if (s1[i][k] != t1[j + k]) {
						ok = false;
						break;
					}
				}

				if (ok) {
					bool pl = true;

					for (int k = 0; k + j < lent; k++) {

						if (s2[i][k] != t2[j + k]) {
							pl = false;
							break;
						}
					}

					if (pl)
						ans++;
				}
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}