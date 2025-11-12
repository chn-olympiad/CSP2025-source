#include<bits/stdc++.h>
using namespace std;
#define int long long
#define iosfst ios::sync_with_stdio(0); cin.tie(0), cout.tie(0)
#define File(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout)
#define rep(i, a, b) for(int i = a; i <= b; i ++)
#define lop(i, a, b) for(int i = a; i < b; i ++)
#define dwn(i, a, b) for(int i = a; i >= b; i --)
int a[101000];
bool cmp(int x, int y) {
	return x > y;
}
signed main(){
	File("seat");
	iosfst;
	int n, m; cin >> n >> m;
	rep(i, 1, n * m) cin >> a[i];
	int cnt = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	rep(i, 1, n * m) {
		if(a[i] == cnt) {
			cnt = i;
			break;
		}
	}
	int ans = 0;
	rep(i, 1, m){
		if(i % 2) {
			rep(j, 1, n) {
				ans ++;
				if(ans == cnt) {
					cout << i << ' ' << j;
					return 0;	
				}
			}
		}
		else {
			dwn(j, n, 1) {
				ans ++;
				if(ans == cnt) {
					cout << i << ' ' << j;
					return 0;
				}
			}
		}
	}
	return 0;
}

