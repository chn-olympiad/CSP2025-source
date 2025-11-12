#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],c[5005][5005],k,st;
bool t=1;
void dfs(int step,int curr,int maxn,int now){
	if(step==k+1){
		if(curr>maxn*2)st++;
		return;
	}
	if(k-step+1>n-now)return;
	for(int i=now+1;i<=n;i++)dfs(step+1,curr+a[i],max(maxn,a[i]),i);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1)t=0;
	}
	c[1][1]=1;
	for(int i=1;i<=5000;i++)c[i][0]=1;
	for(int i=2;i<=5000;i++)
		for(int j=1;j<=i;j++){
			c[i][j]=c[i-1][j]+c[i-1][j-1];
			c[i][j]%=mod;
		}
	if(t){
		int ans=0;
		for(int i=3;i<=n;i++)ans=(ans+c[n][i])%mod;
		cout<<ans;
	}
	else if(n==3){
		int mx=max(a[1],max(a[2],a[3]));
		if(a[1]+a[2]+a[3]>mx*2)cout<<1;
		else cout<<0;
	}
	else if(n<=20){
		for(k=3;k<=n;k++)dfs(1,0,-1,0);
		cout<<st;
	}
	return 0;
}