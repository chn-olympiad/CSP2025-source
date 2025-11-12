#include <bits/stdc++.h> 
#define rep(i, a, b) for(int i = a; i <= b; i++) 
#define per(i, a, b) for(int i = a; i >= b; i--)
#define IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0); 
#define int long long 
#define endl "\n" 
#define lc(i) i << 1ll 
#define rc(i) i << 1ll | 1ll
const int N = 5e5 + 7; 
int a[N]; 

struct Tree{
	int l, r; 
	int xorsum; 
}tree[N << 2];


void push_up(int i) {
	tree[i].xorsum = tree[lc(i)].xorsum ^ tree[rc(i)].xorsum; 
}



void build(int i, int L, int R) {
	tree[i].l = L, tree[i].r = R; 
	if(L == R) {
		tree[i].xorsum = a[L]; 
		return ; 
	}
	
	int mid = (L + R) >> 1; 
	build(lc(i), L, mid); 
	build(rc(i), mid + 1, R); 
	push_up(i); 
}

int query(int i, int L, int R){
	if(L <= tree[i].l && tree[i].r <= R) {
		return tree[i].xorsum; 
	}
	int xorsum = 0; 
	if(tree[lc(i)].r >= L) xorsum ^= query(lc(i), L, R); 
	if(tree[rc(i)].l <= R) xorsum ^= query(rc(i), L, R); 
	return xorsum; 
}

struct test{
	 int l, r, len; 
}p[N];

bool cmp(test x, test y) {
	return x.r > y.r; 
}

void solve() { 
	int n, k; 
	std::cin >> n >> k; 
	bool forA = true; 
	rep(i, 1, n) {
		std::cin >> a[i]; 
		if(a[i] != 1) {
			forA = false; 
		}
	}
	if(k == 0 && forA == true) {
		std::cout << 0 << endl; 
		return ;
	}
	build(1, 1, n);
	int l = 1, r = 1; 
	int cnt1 = 0, cnt2 = 0; 
	int TEST_CNT = 0; 
	while(l <= n) {
		int res = 0; if(l == r) res = a[l]; else res = query(1, l, r); 
		// std::cout << l << " " << r << endl; 
		if(res == k) {
			p[++TEST_CNT].l = l; 
			p[TEST_CNT].r = r; 
			l++; 
			r = l; 
			cnt1++;  
		} else {
			r++; 
		}
		if(r >= n + 1) {
			l++;
			r = l; 
		}
	}
	
	int t = 0; 
	rep(i, 1, TEST_CNT) {
		p[i].len = p[i].r - p[i].l + 1; 
	}
	
	rep(i, 1, TEST_CNT) {
		if(p[i].l == -114514) {
			continue; 
		}
		rep(j, 1, TEST_CNT) {
			if(j == i) continue; 
			if(p[j].l >= p[i].l && p[j].r <= p[i].r && p[j].l != -114514 && p[j].r != -114514) {
				if(p[i].len > p[j].len) {
					p[i].l = -114514, p[i].r = -114514; 
				} else {
					p[j].l = -114514, p[j].r = -114514; 
				}
				cnt1--;
			}// wan quan xiang jiao 
			if(p[j].l >= p[i].l && p[j].l <= p[i].r && p[j].l != -114514 && p[j].r != -114514) {
				if(p[i].len > p[j].len) {
					p[i].l = -114514, p[i].r = -114514; 
				} else {
					p[j].l = -114514, p[j].r = -114514; 
				}
				cnt1--;
			} 
			if(p[j].r <= p[i].r && p[j].r >= p[i].l && p[j].l != -114514 && p[j].r != -114514) {
				if(p[i].len > p[j].len) {
					p[i].l = -114514, p[i].r = -114514; 
				} else {
					p[j].l = -114514, p[j].r = -114514; 
				}
				cnt1--;
			} 
			
		}
	}
	std::sort(p + 1, p + 1 + TEST_CNT, cmp);
//	
//	rep(i,1 , TEST_CNT) {
//		std::cout << p[i].l << " " << p[i].r << endl; 
//	}
	std::cout << cnt1 << endl; 
}
signed main() {
	freopen("xor.in", "r", stdin); 
	freopen("xor.out", "w", stdout); 
	IOS; 
	solve();
	return 0;  
}

/*
3 3
94 95 96 97 98 99 100 93 92
2 2
99 100 97 98

*/
