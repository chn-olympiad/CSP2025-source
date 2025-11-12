#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
#define _for(i, x, y) for(int (i)=(x); (i)<=(y); ++(i))

struct node {
	int tgt;
	int val;
	
	node(int _tgt=0, int _val=0) {
		tgt = _tgt;
		val = _val;
	}
	
	bool operator<(const node &x) const {
		return val < x.val;
	}
	
	bool operator>(const node &x) const {
		return val > x.val;
	}
	
	bool operator==(const node &x) const {
		return val == x.val;
	}
};

struct person {
	node sat[4];
	int id;
	
	void _sort() {
		sort(sat+1, sat+4, greater<node>());
	}
	
	bool operator<(const person &x) const {
		if (sat[1] == x.sat[1]) {
			if (sat[2] == x.sat[2]) {
				return sat[3] < x.sat[3];
			} else {
				return sat[2] < x.sat[2];
			}
		}
		
		return sat[1] < x.sat[1];
	}
	
	bool operator>(const person &x) const {
		if (sat[1] == x.sat[1]) {
			if (sat[2] == x.sat[2]) {
				return sat[3] > x.sat[3];
			} else {
				return sat[2] > x.sat[2];
			}
		}
		
		return sat[1] > x.sat[1];
	}
};

int n;
int c[4];
//person a[maxn];

//void solve1() {
//	int ans = 0;
//	
//	scanf("%d", &n);
//	_for (i, 1, n) {
//		a[i].id = i;
//		_for (j, 1, 3) {
//			node nd(j);
//			scanf("%d", &nd.val);
//			a[i].sat[j] = nd;
//			
//			printf("%d %d\n", nd.tgt, nd.val);
//		}
//		a[i]._sort();
//		printf("\nsorted %d %d %d\n", a[i].sat[1].val, a[i].sat[2].val, a[i].sat[3].val);
//	}
//	
//	sort(a+1, a+1+n, greater<person>());
//	
//	_for (i, 1, n) {
//		person x = a[i];
//		printf("a[%d]:\n", i);
//		_for (j, 1, 3) {
//			printf("%d, ", x.sat[j].val);
//		}
//		puts("");
//	}
//
//	int LIM = n/2;
//	c[1] = c[2] = c[3] = 0;
//	
//	_for (i, 1, n) {
//		person x = a[i];
//		
//		_for (j, 1, 3) {
//			int tgt = x.sat[j].tgt;
//			
//			if (c[tgt]+1 <= LIM) {
//				printf("Give %d 's %d to %d\n", x.id, x.sat[j].val ,tgt);
//				++c[tgt];
//				ans += x.sat[j].val;
//				break;
//			}
//		}
//	}
//	
//	printf("ANS IS ");
//	printf("%d\n", ans);
//}

int dp[maxn][4];
int t[4][4];

int a[maxn][4];

int brutans=0;

void brutdfs(int x, int stp, int l1, int l2, int l3, int LIM) {
	if (x == n) {
//		cout << "stp is " << stp << endl;
	
		int newans=0;
		if (l1 < LIM)
			newans = max(newans, stp+a[x][1]);
		if (l2 < LIM)
			newans = max(newans, stp+a[x][2]);
		if (l3 < LIM)
			newans = max(newans, stp+a[x][3]);
	
		brutans = max(brutans, newans);
		return;
	}
	
	if (l1 < LIM)
		brutdfs(x+1, stp+a[x][1], l1+1, l2, l3, LIM);
	if (l2 < LIM)
		brutdfs(x+1, stp+a[x][2], l1, l2+1, l3, LIM);
	if (l3 < LIM)
		brutdfs(x+1, stp+a[x][3], l1, l2, l3+1, LIM);
}

void solvebrut() {
	brutans = 0;
	brutdfs(1, 0, 0, 0, 0, n/2);
	printf("%d\n", brutans);
}

void solve2() {
	scanf("%d", &n);
	
	_for (i,1, n) {
		memset(dp[i], 0, sizeof(dp[i]));
		_for (j, 1, 3) {
			scanf("%d", &a[i][j]);
		}
	}
	
	if (n <= 20) {
		solvebrut();
		return;
	}

	int LIM = n/2;
	_for (i, 1, 3) {
		_for (j, 1, 3) {
			t[i][j] = 0;
		}
	}
	
	_for (i, 1, n) {
		int newtt[4][4];
		_for (j, 1, 3) {
			// get dp(i, j) from dp(i-1, k)
			int newt[4];
			
			_for (k, 1, 3) {
				// from last k to j
				// only t[j] increases so only check t[j]
				if (t[k][j] < LIM) {
					// viable
					if (dp[i][j] <= dp[i-1][k] + a[i][j]) {
						// should be at least the same
						// update t used
						
						dp[i][j] = dp[i-1][k] + a[i][j];
						newt[j] = t[k][j] + 1;
						
						_for (l, 1, 3) {
							if (l == j) continue;
							newt[l] = t[k][l]; // check
						}				
					}
				} // otherwise not viable
			}
			
			_for (k, 1, 3) {
				newtt[j][k] = newt[k];
			}
		}
		_for (j, 1, 3) {
			_for (k, 1, 3) {
				t[j][k] = newtt[j][k];
			}
		}
	}
	
	printf("%d\n", max(max(dp[n][1], dp[n][2]), dp[n][3]));
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout); 
	int T;
	scanf("%d", &T);
	while (T--) {
		solve2();
	}
	
	return 0;
}
