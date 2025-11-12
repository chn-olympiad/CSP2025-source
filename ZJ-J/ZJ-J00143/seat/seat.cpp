#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
ll n,m,k,x,y;
ll a[101];
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			ll t=(i-1)*m+j;
			cin>>a[t];
			if(a[t]>a[1]){
				k++;
			}
		}
	}
	ll x=1,y=1,f=1;
	while(k--){
		if(f==1){
			x++;
		}else{
			x--;
		}
		if(x==n+1){
			y++;
			x=n;
			if(f==1) f=0;
			else f=1;
		}
		if(x==0){
			y++;
			x=1;
			if(f==1) f=0;
			else f=1;
		}
	}
	cout<<y<<" "<<x;
	
	
	
	return 0;
}
