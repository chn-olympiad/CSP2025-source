#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,ans;
ll a[110],b[20][20];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ans=a[1];
	sort(a+1,a+1+n*m,greater<ll>());
	ll way_x=1,sum_x=1,sum_y=1;
	for(ll i=1;i<=n*m;i++){
		if(a[i]==ans){
			cout<<sum_y<<" "<<sum_x<<"\n";
			return 0;
		}
		b[sum_x][sum_y]=a[i];
		if(sum_x+way_x>n||sum_x+way_x<1){
			sum_y++;
			way_x=-(way_x);
		}else sum_x+=way_x;
	}
	return 0;
}
