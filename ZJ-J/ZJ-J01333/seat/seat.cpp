#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[20],n,m,sum=1,posn=1,posm=1;
ll adj[20][20];
ll  ans;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n*m;++i){
		cin>>a[i];
		if(i==1){
			ans=a[i];
		}
	}
	sort(a+1,a+n*m+1,greater<ll>());
	bool flag=true;
	for(ll i=1;i<=n;++i){
		for(ll j=1;j<=m;++j){
			adj[posn][posm]=a[sum];
			if(flag){
				if(posn<n){
					posn++;
				}else{
					posm++;
					flag=false;	
				}
			}else{
				if(posn>1){
					posn--;
				}else{
					posm++;
					flag=true;
				}
			}
			sum++;
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(adj[i][j]==ans){
				cout<<j<<' '<<i;
				break;
			}
		}
	}
	return 0;
}
