#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t;
ll n;
ll l[5];
struct info{
	ll v;
	ll r;
}a[5][500005];
ll ans = 0;
ll w[500005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		ans = 0;
		memset(l,0,sizeof(l));
		for(ll i = 1;i <= n;i++){
			ll x,y,z;
			scanf("%lld%lld%lld",&x,&y,&z);
			if(x >= y && x >= z){
				++l[1];
				a[1][l[1]].v = x;
				a[1][l[1]].r = x - max(y,z);
			} 
			else{
				if(y >= x && y >= z){
					++l[2];
					a[2][l[2]].v = y;
					a[2][l[2]].r = y - max(x,z);
				} 
				else{
					++l[3];
					a[3][l[3]].v = z;
					a[3][l[3]].r = z - max(x,y);					
				}				
			}
		}
		ll id = 1;
		for(ll i = 2;i <= 3;i++){
			if(l[i] > l[id]){
				id = i;
			}
		}
		for(ll i = 1;i <= 3;i++){
			for(ll j = 1;j <= l[i];j++){
				ans += a[i][j].v;
			}
		}
		for(ll i = 1;i <= l[id];i++){
			w[i] = a[id][i].r;
		}
		sort(w+1,w+l[id]+1);
		for(ll i = 1;i <= l[id] - (n / 2);i++){
			ans -= w[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
/*2
4
4 2 1
3 2 4
5 3 4
3 5 1
4
4 2 1
3 2 4
5 3 4
3 5 1*/
