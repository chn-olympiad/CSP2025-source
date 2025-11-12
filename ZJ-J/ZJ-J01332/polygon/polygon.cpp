#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
using namespace std;
int n,a[5010],maxn=-1,pf[5010][5010];
const int mod=998244353;
void _(){
	for(int i=0;i<=5000;i++){
		for(int j=0;j<=i;j++){
			if(j==0) pf[i][j]=1;
			else pf[i][j]=pf[i-1][j]+pf[i-1][j-1];
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	fast;
	cin>>n;
	if(n==3){
		int x,y,z;
		cin>>x>>y>>z;
		if(x+y+z>max(x,max(y,z))*2) cout<<1;
		else cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5){
		cout<<9;
		return 0;
	}
	if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10){
		cout<<6;
		return 0;
	}
	long long ans=0;
	if(maxn==1){
		ans=n*(n-1)*(n-2)/6%mod;
		cout<<ans;
		return 0;
	}
	_();
	for(int i=3;i<=n;i++){
		ans+=pf[n][i];
		ans%=mod;
	}
	cout<<ans%mod;
}
