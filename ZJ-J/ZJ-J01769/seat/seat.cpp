#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[1145],ans[114][114];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ll p=a[1];
	sort(a+1,a+1+n*m,greater<ll>());
	ll pos=0;
	for(ll i=1;i<=n*m;i++){
		if(a[i]==p){
			pos=i;
			break;
		}
	}
//	cout<<pos<<'\n';
	ll x=1,y=1,tot=1;
	for(ll i=1;i<=m;i++){	
		if(i%2==1){
			while(x<=n){
				ans[x][y]=a[tot];
				x++;tot++;
				
			}
			x--;tot--;
		}else{
			while(x>=1){
				ans[x][y]=a[tot];
				x--;tot++;
			}
			x++;tot--;
		}
	
		y++;tot++;
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			if(ans[i][j]==p){
				cout<<j<<' '<<i;
				return 0;
			}
		}
		
	}
	return 0;
}
