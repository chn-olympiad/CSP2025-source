#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long zd=-1e9;
long long a[5005],b[5005],c[5005];
void dfs(long long u,long long k,long long sum,long long zd,long long x){
	if(u==k){
		if(sum>2*zd){
			ans++;
		}
		return;
	}
	for(int i=x;i<=n;i++){
		if(b[i]==0){
			b[i]=1;
			c[u]=a[i];
			dfs(u+1,k,sum+a[i],max(zd,a[i]),i);
			c[u]=0;
			b[i]=0;
		}
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int k=3;k<=n;k++){
		dfs(0,k,0,-1e9,1);
	}
	cout<<ans%998244353;
	return 0;
}
