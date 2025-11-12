#include<iostream>
#include<algorithm>
#include<cstring>
#include<stdio.h>
using namespace std;
#define ll long long
#define N 200001
ll t,n,d[4][N],ans;
bool ifa,ifb;
inline ll maxll(ll a,ll b){
	return (a>b?a:b);
}
inline ll minll(ll a,ll b){
	return (a<b?a:b);
}
namespace f1{
	ll f[4];
	void dfs(ll x,ll lans){
		if(x==n+1){
			ans=maxll(lans,ans);
			return;
		}
		for(ll i=1;i<=3;i++){
			if(f[i]+1<=n/2){
				f[i]++;
				dfs(x+1,lans+d[i][x+1]);
				f[i]--;
			}
		}
		return;
	}
	void solve(){
		memset(f,0,sizeof(f));
		for(ll i=1;i<=3;i++){
			f[i]++;
			dfs(1,d[i][1]);
			f[i]--;
		}
		cout<<ans<<endl;
		return;
	}
}
namespace f2{
	bool cmp(ll a,ll b){
		return a>b;
	}
	void solve(){
		sort(d[1]+1,d[1]+1+n,cmp);
		for(ll i=1;i<=n/2;i++){
			ans+=d[1][i];
		}
		cout<<ans<<endl;
		return;
	}
}
namespace f3{
	void solve(){
		for(ll i=1;i<=n;i++){
			ans+=maxll(maxll(d[1][i],d[2][i]),d[3][i]);
		}
		cout<<ans<<endl;
		return;
	}
}
namespace f4{
	void solve(){
		
		return;
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(ll T=1;T<=t;T++){
		memset(d,0,sizeof(d));
		ifa=true;
		ifb=true;
		ans=0;
		cin>>n;
		for(ll i=1;i<=n;i++){
			cin>>d[1][i]>>d[2][i]>>d[3][i];
			if(d[2][i]||d[3][i]){
				ifa=false;
			}
			if(d[3][i]){
				ifb=false;
			}
		}
		if(ifa){
			f2::solve();
		}
		/*
		else if(ifb){
			f4::solve();
		}
		*/
		else if(n<=30){
			f1::solve();
		}
		else{
			f3::solve();
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
ll t,n,d[4][N],dp1[4][N/2+1],dp2[4][N/2+1],ans;
inline ll maxll(ll a,ll b){
	return (a>b?a:b);
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(ll T=1;T<=t;T++){
		memset(d,0,sizeof(d));
		memset(dp1,0,sizeof(dp1));
		memset(dp2,0,sizeof(dp2));
		ans=0;
		cin>>n;
		for(ll i=1;i<=n;i++){
			cin>>d[1][i]>>d[2][i]>>d[3][i];
		}
		for(ll i=1;i<=n/2;i++){
			for(ll j=i;j>0;j--){
				for(ll k=1;k<=3;k++){
					dp1[k][j]=maxll(dp1[k][j],dp1[k][j-1]+d[k][i]);
				}
			}
		}
		
		for(ll k=1;k<=3;k++){
			for(ll i=1;i<=n/2;i++){
				cout<<dp1[k][i]<<' ';
			}
			cout<<endl;
		}
		cout<<"/"<<endl;
		
		for(ll i=1;i<=n/2;i++){
			for(ll j=i;j>0;j--){
				for(ll k=1;k<=3;k++){
					dp2[k][j]=maxll(dp2[k][j],dp2[k][j-1]+d[k][i+n/2]);
				}
			}
		}
		
		for(ll k=1;k<=3;k++){
			for(ll i=1;i<=n/2;i++){
				cout<<dp2[k][i]<<' ';
			}
			cout<<endl;
		}
		cout<<"/"<<endl;
		
		for(ll i=0;i<=n/2;i++){
			for(ll j=0,k=n-j-i;j<=n/2 && k<=n/2;j++,k=n-j-i){
				for(ll i1=0;i1<=i;i1++){
					for(ll j1=0;j1<=j;j1++){
						for(ll k1=0;k1<=k;k1++){
							ans=maxll(ans,dp1[1][i1]+dp1[2][j1]+dp1[3][k1]+dp2[1][i-i1]+dp2[2][j-j1]+dp2[3][k-k1]);
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
*/
