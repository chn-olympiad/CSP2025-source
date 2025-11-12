#include<bits/stdc++.h>
using namespace std;
#define int long long
int t , n;
struct sd{
	int x , y , z;
}a[100005];
signed comp(sd a , sd b){
	return a.x > b.x;
}
signed main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	cin >> t;
	while(t --){
		cin >> n;
		for(int i = 1; i <= n; i ++){
			cin >> a[i].x >> a[i].y >> a[i].z;
		}
		sort(a + 1 , a + 1 + n , comp);
		int ans = 0;
		for(int i = 1; i <= n / 2; i ++){
			ans += a[i].x;
		}
		cout << ans;
	}
	return 0;
}