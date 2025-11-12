#include <bits/stdc++.h>
using namespace std;

struct node {
	int id;
	int val;

} a[100002], b[100002], c[100002];
int ji1 = 0, ji2 = 0, ji3 = 0;
int fous, fout;

bool cmp(node a, node b) {
	return a.val > b.val;

}
bool lis[100002];
queue<node>q1, q2, q3;
long long ans = 0;

int main() {
//pq.push((1,2));
//pq.push(1,1);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);

	while (t--) {
		fous = 0;
		fout = 0;
		int n;
		scanf("%d", &n);

		for (int i = 1; i <= n; i++) {

			scanf("%d%d%d", &a[i].val, &b[i].val, &c[i].val);

			if (b[i].val != 0) {
				fous = 1;
			}

			if (c[i].val != 0) {
				fout = 1;
			}

			a[i].id = i;
			b[i].id = i;
			c[i].id = i;

		}

		if (n == 2) {
			int maxn = -1;

			maxn = max(maxn, a[1].val+b[2].val);
			maxn = max(maxn, a[1].val+c[2].val);
			maxn = max(maxn, b[1].val+a[2].val);
			maxn = max(maxn, b[1].val+c[2].val);
			maxn = max(maxn, c[1].val+a[2].val);
			maxn = max(maxn, c[1].val+b[2].val);
			printf("%d", maxn);



		} else {

			sort(a + 1, a + 1 + n, cmp);
			sort(b + 1, b + 1 + n, cmp);
			sort(c + 1, c + 1 + n, cmp);

			if (fous == 0 && fout == 0) {
				//	printf("!(*387");
				for (int i = 1; i <= n / 2; i++) {

					ans += a[i].val;
				}

				printf("%lld\n", ans);
				ans = 0;
			} else {
				ji1 = 0;
				ji2 = 0;
				ji3 = 0;
				memset(lis, 0, sizeof(lis));

				for (int i = 1; i <= n; i++) {

					q1.pop();
					q2.pop();
					q3.pop();
				}

				for (int i = 1; i <= n; i++) {

					q1.push(node{a[i].id, a[i].val});
					q2.push(node{b[i].id, b[i].val});
					q3.push(node{c[i].id, c[i].val});

				}

				//	return 0;
				for (int i = 1; i <= n; i++) {

					node qw, aw, zw;
					qw = q1.front();
					aw = q2.front();
					zw = q3.front();

					if (lis[qw.id]) {
						while (lis[qw.id]) {
							q1.pop();
							qw = q1.front();
						}
					}

					if (lis[aw.id]) {
						while (lis[aw.id]) {
							q2.pop();
							aw = q2.front();
						}
					}

					if (lis[zw.id]) {
						while (lis[zw.id]) {
							q3.pop();
							zw = q3.front();
						}
					}

					if (qw.val == max(qw.val, max(aw.val, zw.val)) && ji1 <= n / 2) {
						//	n--;
						ans += qw.val;
						q1.pop();
						lis[qw.id] = 1;
						ji1++;
					} else if (aw.val == max(qw.val, max(aw.val, zw.val)) && ji2 <= n / 2) {
						//	n--;
						ans += aw.val;
						q2.pop();
						lis[aw.id] = 1;
						ji2++;

					} else if (zw.val == max(zw.val, max(aw.val, qw.val)) && ji3 <= n / 2) {
						//	n--;
						ans += zw.val;
						q3.pop();
						lis[zw.id] = 1;
						ji3++;
					}
				}

				printf("%lld", ans);
			}
		}
	}

	return 0;
}
