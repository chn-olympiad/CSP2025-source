#include <queue>
#include <string>
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define fi first
#define se second
#define pii pair<ll , ll>
#define mk make_pair
#define ls x << 1
#define rs x << 1 | 1
using namespace std;
ll const N = 1e5 + 10;
ll T , n , ans , j;
struct node{
	ll x1 , x2 , x3;
}a[N];
ll check(){
	ll num1 = 0 , num2 = 0 , num3 = 0;
	for (int i = 1;i <= n;i ++){
		if (a[i].x1 > a[i].x2 && a[i].x1 > a[i].x3) num1 ++;
		if (a[i].x2 > a[i].x1 && a[i].x2 > a[i].x3) num2 ++;
		if (a[i].x3 > a[i].x2 && a[i].x3 > a[i].x1) num3 ++;
	}
	if (num1 > n / 2) return 1;
	if (num2 > n / 2) return 2;
	if (num3 > n / 2) return 3;
	return 0;
}
bool cmp(node x , node y){
	if (j == 1) return x.x1 - max(x.x2 , x.x3) > y.x1 - max(y.x2 , y.x3);
	if (j == 2) return x.x2 - max(x.x1 , x.x3) > y.x2 - max(y.x1 , y.x3);
	if (j == 3) return x.x3 - max(x.x2 , x.x1) > y.x3 - max(y.x2 , y.x1);
}
signed main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T --){
		cin >> n;
		ans = 0;
		for (int i = 1;i <= n;i ++){
			cin >> a[i].x1 >> a[i].x2 >> a[i].x3;
			ll minn = min(a[i].x1 , min(a[i].x2 , a[i].x3));
			a[i].x1 -= minn;
			a[i].x2 -= minn;
			a[i].x3 -= minn;
			ans += minn;
		}
		if (check()){
			j = check();
			sort(a + 1 , a + n + 1 , cmp);
			for (int i = 1;i <= n;i ++){
				if (i <= n / 2){
					if (j == 1) ans += a[i].x1;
					if (j == 2) ans += a[i].x2;
					if (j == 3) ans += a[i].x3;
				}
				else {
					if (j == 1) ans += max(a[i].x2 , a[i].x3);
					if (j == 2) ans += max(a[i].x1 , a[i].x3);
					if (j == 3) ans += max(a[i].x2 , a[i].x1);
				}
			}
			cout << ans << "\n";
		}
		else {
			for (int i = 1;i <= n;i ++) ans += max(a[i].x1 , max(a[i].x2 , a[i].x3));
			cout << ans << "\n";
		}
	}
	return 0;
}
/*

*/