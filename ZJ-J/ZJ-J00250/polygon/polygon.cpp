#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define max(a,b) (a>b)?a:b
const ll mod=998244353;
ll n,a[5004],ans,maxx,js[5004];
void dfs(int s,int zd,int h,int gen){
	if(s>n){
	  if(gen>=3&&h>2*zd)
	    ans++,ans%=mod;
	  return ;
	}
	dfs(s+1,zd,h,gen);
	dfs(s+1,a[s],h+a[s],gen+1);
	return ;
}
int ksm(int x,int y){
	int res=1;
	while(y){
	  if(y&1)
	    res=res*x%mod;
	  y>>=1;
	  x=x*x%mod;
	}
	return res;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	js[0]=1;
	for(int i=1;i<=n;i++)
	  cin>>a[i],js[i]=js[i-1]*i;
	sort(a+1,a+1+n);
	if(a[n]==1){
	  for(int i=3;i<=n;i++)
	    ans=(ans+js[n]*ksm(js[i],mod-2)%mod*ksm(js[n-i],mod-2)%mod)%mod;
	  cout<<ans;
	  return 0;
	}
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}
