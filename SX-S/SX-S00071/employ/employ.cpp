#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510,mod=998244353;
int s[N],c[N],n,m,dis[N],ans;
bool vis[N];
bool check(int n,int m){
	int now=0,bj=0;
	for(int i=1;i<=n;i++){
		if(bj>=c[dis[i]]){
			bj++;
		}else{
			if(s[i]==0) bj++;
			else now++;
		}
//		cout<<dis[i]<<endl;
	}
//	cout<<endl;
//	cout<<now<<' '<<bj<<endl;
	return now>=m;
}
void dfs(int k,int n,int m,int bj){
	if(k>n){
		ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dis[k]=i;
			if(bj>=c[i]||s[k]==0){
				if(n-bj-1>=m){
					dfs(k+1,n,m,bj+1);
				}
			}else{
				dfs(k+1,n,m,bj);
			}
			vis[i]=0;
		}
	}
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%1lld",&s[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
	}
	dfs(1,n,m,0);
	cout<<ans<<endl;
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/