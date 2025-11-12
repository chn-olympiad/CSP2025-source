#include<bits/stdc++.h>
using namespace std;
const long long mod=998224353;
long long n,ans=0,a[5005],vis[5005],v[5005],pos;
void dfs(long long step,long long maxn,long long sum,int x){
	if(step>=3&&maxn*2<sum){
		ans++;
		ans=ans%mod;
	}if(step>n){
		return;
	} for(int i=x;i<=n;i++){
		if(vis[i]==0){
			v[step+1]=a[i];
			vis[i]=1;
			dfs(step+1,max(maxn,a[i]),sum+a[i],i);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0,0,1);
	cout<<ans;
	return 0;
}
