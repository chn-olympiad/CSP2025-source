#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[5005];
const int mod=998244353;
int c[5005];
int f[5005];
int ans=0;
inline void dfs(int x,int u,int last){
	if(u>x){
		int mx=0,sum=0;
		for(int i=1;i<=x;++i){
			mx=max(mx,c[i]);
			sum+=c[i];
		}
		
		if(sum>2*mx){
			ans++;/*
			for(int i=1;i<=x;++i){
				cout<<c[i]<<' ';
			}
			//cout<<mx<<'\n';
			cout<<'\n';*/
		}
		
		return;
	}
	for(int i=last+1;i<=n;++i){
		if(!f[i]){
			c[u]=a[i];
			f[i]=1;
			dfs(x,u+1,i);
			f[i]=0;
		}
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=3;i<=n;++i){
		dfs(i,1,0);
	}
	cout<<ans%mod;
	return 0;
}
