#include <bits/stdc++.h>
using namespace std;
long long n, q, tot = 0;

struct rt {
	string from;
	string to;
} s[200010], que[200010];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	scanf("%lld%lld", &n, &q);
	for (int i = 1; i <= n; i++) {
		cin >> s[i].from >> s[i].to;
	}
	for (int i = 1; i <= q; i++) {
		cin >> que[i].from >> que[i].to;
	}
	for (int i = 1; i <= q; i++) {
		if (que[i].from.size() != que[i].to.size()) {
			printf("0\n");
			continue;
		}
		long long f;
		string u;
		for (int j = 0; j < que[i].from.size(); j++) {
			for (int k = 1; k <= n; k++) {
				f = 1;
				u = que[i].from;
				for (int moi = 0; moi < s[k].from.size() ; moi++) {
					if (que[i].from[j] != s[k].from[moi])
						f = 0;
				}
				if (f == 1) {
					u = que[i].from.replace(j, s[k].from.size() + 0, s[k].to);

					que[i].from.replace(j, s[k].to.size() + 0, s[k].from);
				}
				if (f == 1 && u == que[i].to) {

					tot++;
				}
			}
		}
		printf("%lld\n", tot);
	}
	return 0;
}
