#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100010;

int T;
int n, a[N][4], id[N][4], s[4];
struct node {
	int a, id;
	bool operator < (const node &A) const {
		return a > A.a; 
	}
} c[4];
struct Node {
	int x, n, mx, idx;
	bool operator < (const Node &A) const {
		if(n != A.n)
			return n > A.n;
		if(x != A.x)
			return x > A.x; 
	}
} b[N]; 

void solve() {
	scanf("%d", &n);
	int cnt = 0;
	ll sum = 0;
	s[1] = s[2] = s[3] = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
		c[1].a = a[i][1], c[1].id = 1;
		c[2].a = a[i][2], c[2].id = 2;
		c[3].a = a[i][3], c[3].id = 3;
		sort(c + 1, c + 3 + 1);
		cnt++;
		sum += c[1].a;
		b[cnt].x = c[1].a - c[3].a;
		b[cnt].n = c[1].a - c[2].a;
		b[cnt].idx = i;
		id[i][1] = c[1].id;
		id[i][2] = c[2].id;
		id[i][3] = c[3].id;
	}
	sort(b + 1, b + n + 1);
	for(int i = 1; i <= n; i++) {
		if(s[id[b[i].idx][1]] < (n / 2)) {
			s[id[b[i].idx][1]]++;
		} else if(s[id[b[i].idx][2]] < (n / 2)) {
			s[id[b[i].idx][2]]++;
			sum -= b[i].n;
		} else {
			s[id[b[i].idx][3]]++;
			sum -= b[i].x;
		}
	}
	printf("%lld\n", sum);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while(T--)
		solve();
	return 0;
}
