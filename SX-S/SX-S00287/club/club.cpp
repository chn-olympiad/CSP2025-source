#include <bits/stdc++.h>
using namespace std;
long long a[100010][5];
int b[100010];

struct node {
	int id;
	long long x;
	bool operator < (const node &cnt)const {
		return x < cnt.x;
	}
};
priority_queue<node>q1, q2;
priority_queue<long long>q;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				scanf("%lld", &a[i][j]);
			}
		}
		while (!q1.empty())
			q1.pop();
		while (!q2.empty())
			q2.pop();
		while (!q.empty())
			q.pop();
		long long sum = 0;
		for (int i = 1; i <= n / 2; i++) {
			b[i] = 1;
			sum += a[i][1];
			node h;
			h.id = i;
			h.x = a[i][2] - a[i][1];
			q1.push(h);
		}
		for (int i = n / 2 + 1; i <= n; i++) {
			b[i] = 2;
			sum += a[i][2];
			node h;
			h.id = i;
			h.x = a[i][1] - a[i][2];
			q2.push(h);
		}
		while (!q1.empty()) {
			node t1 = q1.top();
			q1.pop();
			node t2 = q2.top();
			q2.pop();
			//printf("%d %d %d\n", t1.id, t2.id, t1.x + t2.x);
			if (t1.x + t2.x < 0) {
				break;
			} else {
				sum += t1.x + t2.x;
				b[t1.id] = 2;
				b[t2.id] = 1;
			}
		}
		for (int i = 1; i <= n; i++) {
			long long h = a[i][3] - a[i][b[i]];
			q.push(h);
		}
		int cnt = 0;
		while (!q.empty() && cnt <= n / 2) {
			long long t = q.top();
			q.pop();
			if (t < 0)
				break;
			cnt++;
			sum += t;
		}
		printf("%lld", sum);
	}
	return 0;
}
