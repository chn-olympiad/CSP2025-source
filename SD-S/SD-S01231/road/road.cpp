#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int KmaxN = 1e6 + 5e5 + 10;

ll ans = 0;
ll sum = 0;

int n, m, k;
int idx, l;

int f[KmaxN];

struct node {
	int a, b;
	ll c;
	bool operator < (const node & other) const {
		return c < other.c;
	}
}p[KmaxN];

int find(int x) {
	if (x != f[x]) {
		f[x] = find(f[x]);
	}
	return f[x];
}

void kruskal() {
	sort(p + 1, p + m + 1);
	
	for (int i = 1; i <= m; i++) {
		int a = p[i].a, b = p[i].b;
		int fa = find(a);
		int fb = find(b);
		if (fa != fb) {
			f[fa] = fb;
			sum += p[i].c;
		}
	}
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		f[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		int a, b;
		ll c;
		scanf("%d%d%lld", &a, &b, &c);
		p[i] = {a, b ,c};
	}
	kruskal();
	if (k == 0) {
		printf("%lld", sum);
		return 0;
	}
	
	for (int i = 0; i <= n * 2; i++) {
		f[i] = i;
	}
	ans = 0;
	
	idx = m;
	l = n;
	
	for (int i = 1; i <= k; i++) {
		ll v;
		scanf("%lld", &v);
		l++;
		if (v != 0) {
			p[++idx] = {n * 2, l, v};
		}
		for (int j = 1; j <= n; j++) {
			ll c;
			scanf("%lld", &c);
			p[++idx] = {j, l, c};
		}
	}
	
	sort(p + 1, p + idx + 1);
	
	for (int i = 1; i <= idx; i++) {
		int a = p[i].a, b = p[i].b;
		int fa = find(a);
		int fb = find(b);
		if (fa != fb) {
			f[fa] = fb;
			ans += p[i].c;
		}
	}
	
	printf("%lld", min(sum, ans));
	return 0;
}
/*
对于k==0，跑一边kruskal应该就行了
其余的，建立虚拟节点0号节点，与这k个节点建立联系
然后再把这些边建起来，在跑一边kruskal，偏分 
*/
