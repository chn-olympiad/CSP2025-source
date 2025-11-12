#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e5+10;
ll t,a[N][5],vis[5];
ll ans;

void sovle(ll i,ll w,ll s){
	if(i>s){
		ans=max(ans,w);
		return ;
	}
	for(ll j=1;j<=3;j++){
		if(vis[j]>=(s>>1)) continue;
		vis[j]++;
		sovle(i+1,w+a[i][j],s);
		vis[j]--;
	}
	return ;
}

int main(){
	freopen("club.in.txt","r",stdin);
	freopen("club.out.txt","w",stdout);
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=3;j++){
				cin >> a[i][j];
			}
		} 
		sovle(1,0,n);
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=3;j++){
				a[i][j]=0;
			}
		}
		for(ll i=1;i<=3;i++) vis[i]=0;
		cout << ans << endl;
		ans=0;
	}
	return 0;
} 