#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define mem(a , b) memset(a , b , sizeof a)
using namespace std;
const int N = 1e5+10;
ll n , m , T;
struct fF{
	ll a , b;
	int i;
	bool operator<(const fF&GFX) const {
		return (a - b) > (GFX.a - GFX.b);
	}
}a[N];
struct MCY {
	ll num;
	int i;
	bool operator<(const MCY&GFX) const {
		return num > GFX.num;
	}
}tmp[3];
ll cnt[3];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	cin >> T;
	while(T--) {
		ll ans = 0;
		cin >> n;
		m = n/2;
		cnt[0] = cnt[1] = cnt[2] = 0;
		for(int i = 1 ; i <= n ; i++) {
			cin >> tmp[0].num >> tmp[1].num >> tmp[2].num;
			tmp[0].i = 0; tmp[1].i = 1; tmp[2].i = 2;
			sort(tmp , tmp+3);
			a[i].a = tmp[0].num;
			a[i].b = tmp[1].num;
			a[i].i = tmp[0].i;
		}
		sort(a+1 , a+1+n);
//		for(int i = 1 ; i <= n ; i++) {
//			cout << a[i].a << a[i].b << a[i].i << '\n';
//		}
		for(int i = 1 ; i <= n ; i++) {
			if(cnt[a[i].i]++ >= m) ans += a[i].b;
			else ans += a[i].a;
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/

