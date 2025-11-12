#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,a[1111],ans,time_count,pw[222];
bool vis[1111],vis1[1<<21];
void dfs(int nw){
	//time_count+=1;
	if (nw==n+2){
		return ;
	}
	int sum=0,mx=0,cnt=0;
	for (int i=1;i<=n;++i){
		if (vis[i]){
			mx=max(mx,a[i]);
			cnt+=1;
			sum+=a[i];
		}
	}
	int ssm=0;
	for (int i=1;i<=n;++i){
		ssm+=vis[i]*pw[n-i];
	}
	if (sum>2*mx && cnt>=3 && vis1[ssm]==0){
		ans=(ans+1)%mod;
		vis1[ssm]+=1;
//		cout<<"AAA"<<endl;
//		cout<<sum<<" "<<mx<<" "<<cnt<<endl;
//		cout<<nw<<endl;
//		for (int i=1;i<=n;++i){
//			cout<<vis[i]<<" ";
//		}
//		cout<<endl;
	}
	vis[nw]=1;
	dfs(nw+1);
	vis[nw]=0;
	dfs(nw+1);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	pw[0]=1;
	for (int i=1;i<=n;++i){
		pw[i]=pw[i-1]*2%mod;
	}
	bool f=0;
	for (int i=1;i<=n;++i){
		cin>>a[i];
		if (a[i]>1){
			f=1;
		}
	}
	if (!f){
		cout<<((((pw[n])%mod-(n*(n-1)%mod)/2+mod)%mod-n+mod)%mod-1+mod)%mod<<endl;
		return 0;	
	}
	dfs(1);
	cout<<ans<<endl;
//	for (int i=3;i<=13;++i){
//		memset(vis,0,sizeof vis);
//		memset(vis1,0,sizeof vis1);
//		for (int j=1;j<=i;++j){
//			a[j]=1;
//		}
//		n=i;
//		dfs(1);
//		cout<<ans<<endl;
//		ans=0;
//	}
	return 0;
}
/*
2 2
2 99 100 97 98
*/
