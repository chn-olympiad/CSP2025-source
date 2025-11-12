#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[5005],b[5005],c[5005][5005];
bool vis[5005];
int sum;int mod=998244353;
int check(){
	int sum=0,mx=0;
	for(int i=1;i<=n;i++){
		if(vis[a[i]]){
			sum+=a[i];
			mx=max(mx,a[i]);
		}
	}
	return (int)(sum>mx*2);
}
void dfs(int step){
	if(step>n){
	ans+=check();
		return ;
	}
	vis[step]=true;
	dfs(step+1);
	vis[step]=false;
	dfs(step+1);
}
bool flag;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(mx==1){
		for(int i=1;i<=n-2;i++){
			long long ans=1;
			for(int j=1;j<=i;j++){
				ans*=j%mod;
			}
			sum+=ans%mod;
		}
		flag=true;
	}
	if(!flag){
		dfs(0);
		cout<<ans/2<<endl;
		return 0;
	}
	cout<<sum%mod<<endl;
	return 0;
}
