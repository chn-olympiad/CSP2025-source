#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long f[5005];
void dfs(long long u,long long mx,int h,int sm){
	if(sm>mx*2&&h>=3){
		ans+=1;
	}
	if(u!=n){
		for(int i=u+1;i<=n;i++){
			dfs(i,max(mx,f[i]),h+1,sm+f[i]);
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>f[i];
	}
	for(int i=1;i<=n;i++){
		dfs(i,f[i],1,f[i]);
	}
	cout<<ans%998244353;
	return 0;
}

