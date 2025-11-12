#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,q=1,z,x,y;
ll a[100+10][100+10];
ll mp[10000+10];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>mp[1];
	z=mp[1];
	for(ll i=2;i<=n*m;i++){
		cin>>mp[i];
	}
	sort(mp+1,mp+1+n*m,greater<ll>());
	for(ll i=1;i<=m;i++){
		if(i%2==0){
			for(ll j=n;j>0;j--){
				a[i][j]=mp[q];
				q++;
				if(mp[q-1]==z){
					x=i;
					y=j;
				}
			} 
		}else{
			for(ll j=1;j<=n;j++){
				a[i][j]=mp[q];
				q++;
				if(mp[q-1]==z){
					x=i;
					y=j;
				}
			}
		}
	}
	cout<<x<<' '<<y;
	return 0;
}
