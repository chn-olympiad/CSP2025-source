#include<bits/stdc++.h>
using namespace std;
#define ll int
ll n,m,a[225],R,mp[15][15],cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++)cin>>a[i];
	R=a[1];
	sort(a+1,a+1+n*m);
	reverse(a+1,a+1+n*m);
	for(ll j=1;j<=m;j++){
		if(j&1){
			for(ll i=1;i<=n;i++)mp[i][j]=a[++cnt];
		}else{
			for(ll i=n;i>0;i--)mp[i][j]=a[++cnt];
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			if(mp[i][j]==R){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}
