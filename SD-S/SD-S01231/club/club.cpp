#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int KmaxN = 1e5 + 5;
int _;
int ans = 0;
int cnta = 0, cntb = 0, cntc = 0;
int n;

struct node {
	int a, b, c;
}p[KmaxN];

struct rec {
	int ma, mid, mi;
	int pos;
	bool operator < (const rec & other) {
		if (ma == other.ma) {
			if (mid == other.mid) {
				return mi > other.mi;
			}
			return mid > other.mid;
		}
		return ma > other.ma;
	}
}r[KmaxN];

bool CheckI() {
	for (int i = 1; i <= n; i++) {
		if (p[i].b || p[i].c) {
			return false;
		}
	}
	return true;
}

bool CheckII() {
	for (int i = 1; i <= n; i++) {
		if (p[i].c) {
			return false;
		}
	}
	return true;
}

bool cmp1(node l, node r) {
	return l.a > r.a;
}

bool cmp2(node l, node r) {
	return l.a - l.b > r.a - r.b;
}

void SolveI() {
	sort(p + 1, p + n + 1, cmp1);
	ans = 0;
	
	for (int i = 1; i <= n / 2; i++) {
		ans += p[i].a;
	}
	
	printf("%d\n", ans);
}

void SolveII() {
	sort(p + 1, p + n + 1, cmp2);
	ans = 0;
	
	for (int i = 1; i <= n / 2; i++) {
		ans += p[i].a;
	}
	for (int i = n / 2 + 1; i <= n; i++) {
		ans += p[i].b;
	}
	
	printf("%d\n", ans);
}

void dfs(int h, int ac, int bc, int cc, int sum) {
	if (ac > n / 2 || bc > n / 2 || cc > n / 2) {
		return ;
	}
	if (h == n + 1) {
		ans = max(ans, sum);
		return ;
	}
	
	for (int i = 1; i <= 3; i++) {
		if (i == 1) {
			dfs(h + 1, ac + 1, bc, cc, sum + p[h].a);
		}
		if (i == 2) {
			dfs(h + 1, ac, bc + 1, cc, sum + p[h].b);
		}
		if (i == 3) {
			dfs(h + 1, ac, bc, cc + 1, sum + p[h].c);
		}
	}
}

void solve() {
	scanf("%d", &n);
	ans = 0;
	cnta = 0, cntb = 0, cntc = 0;
	
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		p[i] = {a, b, c};
		int ma = max(a, max(b, c));
		int mi = min(a, min(b, c));
		int mid = a + b + c - ma - mi;
		r[i] = {ma, mid, mi, i};
	}
	
	if (CheckI()) {
		SolveI();
		return ;
	}
	if (CheckII()) {
		SolveII();
		return ;
	}
	
	if (n <= 10) {
		dfs(1, 0, 0, 0, 0);
		printf("%d\n", ans);
		return ;
	}
	
	sort(r + 1, r + n + 1);
	
	for (int i = 1; i <= n; i++) {
		int pos = r[i].pos;
		int ma = r[i].ma;
		int mid = r[i].mid;
		int mi = r[i].mi;
		
		if (ma == p[pos].a) {
			if (cnta < n / 2) {
				cnta++;
				ans += ma;
				continue;
			}
			else {
				if (mid == p[pos].b) {
					if (cntb < n / 2) {
						cntb++;
						ans += mid;
						continue;
					}
					else {
						cntc++;
						ans += mi;
						continue;
					}
				}
				else {
					if (cntc < n / 2) {
						cntc++;
						ans += mid;
						continue;
					}
					else {
						cntb++;
						ans += mi;
						continue;
					}
				}
			}
		}
		else if (ma == p[pos].b) {
			if (cntb < n / 2) {
				cntb++;
				ans += ma;
				continue;
			}
			else {
				if (mid == p[pos].a) {
					if (cnta < n / 2) {
						cnta++;
						ans += mid;
						continue;
					}
					else {
						cntc++;
						ans += mi;
						continue;
					}
				}
				else {
					if (cntc < n / 2) {
						cntc++;
						ans += mid;
						continue;
					}
					else {
						cnta++;
						ans += mi;
						continue;
					}
				}
			}
		}
		else {
			if (cntc < n / 2) {
				cntc++;
				ans += ma;
				continue;
			}
			else {
				if (mid == p[pos].a) {
					if (cnta < n / 2) {
						cnta++;
						ans += mid;
						continue;
					}
					else {
						cntb++;
						ans += mi;
						continue;
					}
				}
				else {
					if (cntb < n / 2) {
						cntb++;
						ans += mid;
						continue;
					}
					else {
						cnta++;
						ans += mi;
						continue;
					}
				}
			}
		}
	}
	
	printf("%d\n", ans);
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d", &_);
	while (_--) {
		solve();
	}
	return 0;
}
/*
对于只有一个非0的情况，只需要排序之后找前n/2个
对于两个不是0，计算选A而不选B的价值，从大到小排序即可 
这样做是有后效性的，因此考虑贪心 
对于n<=10，直接dfs 

首先将所有的东西都放入最大值，
然后将改变的代价从小到大排序，如果说超了，将改变最小的换一下
使用优先队列来维护 
*/
