#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[100007][3],dp[107][107][107],ne[114514];
struct node{
	ll id,v;
	bool operator<(const node&x)const{
		return v>x.v;
	}
}nt[114514];
void main1(){
	memset(dp,0,sizeof(dp));
	for(ll l=1;l<=n;l++)
	for(ll i=n/2;i>=0;i--){
		for(ll j=n/2;j>=0;j--){
			for(ll k=n/2;k>=0;k--){
				if(i+j+k==0)continue;
				if(j+i+k>n)continue;
				if(i){
					dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[l][0]);
				}
				if(j)dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+a[l][1]);
				if(k)dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]+a[l][2]);
			}
		}
	}
	ll ans=0;
	for(ll i=0;i<=n/2;i++){
		for(ll j=0;j<=n/2;j++){
			if(i+j<n/2)continue;
			ans=max(ans,dp[i][j][n-i-j]);
		}
	}
	cout<<ans<<'\n';
}
void main2(){
	for(ll i=1;i<=n;i++){
		ne[i]=a[i][0];
	}
	sort(ne+1,ne+1+n,greater<ll>());
	ll ans=0;
	for(ll i=1;i<=n/2;i++){
		ans+=ne[i];
	}
	cout<<ans<<'\n';
}
void main3(){
	for(ll i=1;i<=n;i++){
		nt[i]={i,a[i][0]-a[i][1]};
	}
	sort(nt+1,nt+1+n);
	ll ans=0;
//	for(ll i=1;i<=n;i++){
//		cout<<nt[i].id<<' '<<nt[i].v<<'\n';
//	}
	for(ll i=1;i<=n/2;i++){
		ans+=a[nt[i].id][0];
	}
	for(ll i=n/2+1;i<=n;i++){
		ans+=a[nt[i].id][1];
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll T;
	cin>>T;
	while(T--){
		cin>>n;
		ll f1=1,f2=1;
		for(ll i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][2]+a[i][1])f1=0;
			if(a[i][2])f2=0;
		}
		if(n<=30)main1();
		else if(f1)main2();
		else if(f2)main3();
	}
	
	
	return 0;
}