#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[1005];
ll tot = 1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i = 1;i <= n * m;i++){
		scanf("%lld",&a[i]);
	}
	for(ll i = 2;i <= n * m;i++){
		if(a[i] > a[1]){
			tot++;
		}
	}
	ll x = 1;//ÁÐ 
	ll y = 0;//ÐÐ
	for(ll i = 1;i <= tot;i++){
		if(x % 2){
			y++;
			if(y > n){
				y = n;
				x++;
			}	
		}
		else{
			y--;
			if(y < 1){
				y = 1;
				x++;
			}
		}
	}
	printf("%lld %lld",x,y);
	return 0;
}
/*3 3
29 8 37 28 91 38 1 2 45*/
