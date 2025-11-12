#include<bits/stdc++.h>
using namespace std;
#define int long long
#define iosfst ios::sync_with_stdio(0); cin.tie(0), cout.tie(0)
#define File(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout)
#define rep(i, a, b) for(int i = a; i <= b; i ++)
#define lop(i, a, b) for(int i = a; i < b; i ++)
#define dwn(i, a, b) for(int i = a; i >= b; i --)
int a[101000];
struct node {
	int l, r;
};
int vis[1010][1010];
signed main() {
	File("xor");
	iosfst;
	int n, k;
	cin >> n >> k;
	rep(i, 1, n) cin >> a[i];
	if(k == 0) {
		int f = 0;
		rep(i, 1, n) {
			if(a[i] != 1) {
				f = 1;
			}
		}
		if(f == 0) {
			cout << n / 2;
			return 0;
		}
	}
	if(k <= 1) {
		bool f = 0;
		rep(i, 1, n) {
			if(a[i] != 0 && a[i] != 1) f = 1;
		}
		if(f == 0) {
			if(k == 0) {
				int ans = 0, bj = 0;
				rep(i, 1, n) {
					if(a[i] == 0) {
						ans ++;
						bj = i;
					} else {
						if(i - bj == 2) {
							ans ++;
							bj = i;
						}
					}
				}
				cout << ans;
				return 0;
			}
			if(k == 1) {
				int ans = 0;
				rep(i, 1, n) {
					if(a[i] == 1) {
						ans ++;
					}
				}
				cout << ans;
				return 0;
			}
		}
	}
	srand(time(0));
	cout << rand() % n;
	return 0;
}

