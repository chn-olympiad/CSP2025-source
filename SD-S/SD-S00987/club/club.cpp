#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 1e5 + 10;

struct node{
	ll a, b, c;
} A[N];


struct node1{
	ll c, op, id;
	bool operator<(const node1 &a) const{
		return c > a.c;
	}	
};

priority_queue<node1> Q1, Q2, Q3;

ll cnt[5];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ll T, c, ans, n;
	cin >> T;
	node1 t;
	while (T--) {
		cin >> n;
		while(Q1.size()) Q1.pop();
		while(Q2.size()) Q2.pop();
		while(Q3.size()) Q3.pop();
		memset(cnt, 0, sizeof cnt);
		ans = 0;
		for (int i = 1; i <= n; i++) scanf("%lld%lld%lld", &A[i].a, &A[i].b, &A[i].c);
		for (int i = 1; i <= n; i++) {
			if (A[i].a > max(A[i].b, A[i].c)) {
				if (cnt[1] < n / 2) {
					cnt[1]++;
					if (A[i].b > A[i].c) c = 2;
					else c = 3;
					ans += A[i].a;
					Q1.push((node1){A[i].a - max(A[i].b, A[i].c), c, i});
				} else {
					t = Q1.top();
					if (t.c < A[i].a - max(A[i].b, A[i].c)) {
						Q1.pop();
						ans -= A[t.id].a;
						if (t.op == 2) ans += A[t.id].b;
						else ans += A[t.id].c;
						if (A[i].b > A[i].c) c = 2;
						else c = 3;
						ans += A[i].a;
						Q1.push((node1){A[i].a - max(A[i].b, A[i].c), c, i});
					} else ans += max(A[i].c, A[i].b);
				}
			} else if (A[i].b > max(A[i].a, A[i].c)){
				if (cnt[2] < n / 2) {
					cnt[2]++;
					if (A[i].a > A[i].c) c = 1;
					else c = 3;
					ans += A[i].b;
					Q2.push((node1){A[i].b - max(A[i].a, A[i].c), c, i});
				} else {
					t = Q2.top();
					if (t.c < A[i].b - max(A[i].a, A[i].c)) {
						Q2.pop();
						ans -= A[t.id].b;
						if (t.op == 1) ans += A[t.id].a;
						else ans += A[t.id].c;
						if (A[i].a > A[i].c) c = 1;
						else c = 3;
						ans += A[i].b;
						Q2.push((node1){A[i].b - max(A[i].a, A[i].c), c, i});
					} else ans += max(A[i].a, A[i].c);
				}
			} else {
				if (cnt[3] < n / 2) {
					cnt[3]++;
					if (A[i].a > A[i].b) c = 1;
					else c = 2;
					ans += A[i].c;
					Q3.push((node1){A[i].c - max(A[i].a, A[i].b), c, i});
				} else {
					t = Q3.top();
					if (t.c < A[i].c - max(A[i].a, A[i].b)) {
						Q3.pop();
						ans -= A[t.id].c;
						if (t.op == 1) ans += A[t.id].a;
						else ans += A[t.id].b;
						if (A[i].a > A[i].b) c = 1;
						else c = 2;
						ans += A[i].c;
						Q3.push((node1){A[i].c - max(A[i].a, A[i].b), c, i});
					} else ans += max(A[i].a, A[i].b);
				}
			}
		}
		printf("%lld\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
