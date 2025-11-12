#include<bits/stdc++.h>
#define Tie ios::sync_with_stdio(false),cin.tie(0),cout.tie(0); 
using namespace std;
int n,m,c[505],tt[505];
bool vis[505];
int ans=0;
int maxx=0;
void dfs(int k,int d,int l){
	if(k>n){
		if(d>=m){
			ans=(ans+1)%998244353;
		}
		return ;
	}
	if(n-k+1+d<m){
		return ;
	}
	if(d<m&&l>=maxx){
		return ;
	}
	for(int i=1;i<=n;++i){
		if(vis[i]==0){
			vis[i]=1;
			if(l>=c[i]){
				dfs(k+1,d,l+1);
			}
			else if(tt[k]==1){
				dfs(k+1,d+1,l);
			}
			else{
				dfs(k+1,d,l+1);
			}
			vis[i]=0;
		}
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	Tie
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		char x;
		cin>>x;
		tt[i]=x-'0';
	}
	for(int i=1;i<=n;++i){
		cin>>c[i];
		maxx=max(maxx,c[i]);
	}
	dfs(1,0,0);
	cout<<ans<<'\n';
	return 0;
}
