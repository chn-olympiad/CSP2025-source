#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[200000][5];
ll a[200000][8];

ll c[200000];
bool check1(ll n){
	for(ll i=1;i<=n;i++){
		if(a[i][3]!=0)return 0;
		if(a[i][2]!=0)return 0;
	}
	return 1;
}
int main(){
	freopen("club.in","w",stdin);
	freopen("club.out","a",stdout);
	
	ll t;
	cin>>t;
	
	for(ll ii=1;ii<=t;ii++){
		ll n;
		cin>>n;
		
		for(ll i=1;i<=n+2;i++){
			dp[i][1]=0;
			dp[i][2]=0;
			dp[i][3]=0;
		}
		
		
		ll ma=0;
		for(ll i=1;i<=n;i++){
			cin>>a[i][1];
			cin>>a[i][2];
			cin>>a[i][3];
		}
		
		if(check1(n)==1){
			for(ll i=1;i<=n;i++){
				c[i]=a[i][1];	
			}
			sort(c+1,c+n+1);
			ll sum=0;
			for(ll i=n;i>=n/2+1;i--){
				sum+=c[i];	
			}
			cout<<sum;
			continue;
		}
		
		
		ll g=n/2;
		ll f1=0,f2=0,f3=0;
		dp[1][1]=a[1][1];
		dp[1][2]=a[1][2];
		dp[1][3]=a[1][3];
		ma=max(a[1][1],max(a[1][2],a[1][3]));
		if(ma==a[1][1])f1++;
		else if(ma==a[1][2])f2++;
		else if(ma==a[1][3])f3++;
		
		for(ll i=2;i<=n;i++){
			ma=0;
			ma=max(a[i][1],max(a[i][2],a[i][3]));
			if(ma==a[i][1])f1++;
			else if(ma==a[i][2])f2++;
			else if(ma==a[i][3])f3++;
		
			if(f1<=g)dp[i][1]=max(dp[i-1][1],a[i][1])+ma;
			if(f2<=g)dp[i][2]=max(dp[i-1][2],a[i][2])+ma;
			if(f3<=g)dp[i][3]=max(dp[i-1][3],a[i][3])+ma;
		}
		ll mm=max(dp[n][1],max(dp[n][2],dp[n][3]));
		cout<<mm<<endl;
	}
	return 0;
} 
