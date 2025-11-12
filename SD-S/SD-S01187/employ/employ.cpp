#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=510,mod=998244353;
int n,m,s[N],c[N],cnt,ans;
int p[N],vis[N];
int res=0;
void dfs(int k){
	if( k==n+1 ){
		int tot=0,pic=0;
		for(int i=1;i<=n;i++){
			if(tot>=c[p[i]])++tot;
			else if( !s[i] )++tot;
			else ++pic;
		}
		if( pic>=m )++res;
		return ;
	}
	for(int i=1;i<=n;i++){
		if( !vis[i] ){
			vis[i]=1;
			p[k]=i;
			dfs(k+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%1d",&s[i]);
		if( s[i] )++cnt;
	}
	if(cnt<m){
		cout<<0;return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]!=0)++ans;
	}
	if(ans<m){
		cout<<0;return 0;
	}
	if(cnt==n){
		res=1;int j=0;
		for(int i=1;i<=n;i++){
			++j;
			res=(res*max((c[i]),1ll))%mod;
		}
		cout<<res<<endl;
	}else {
		dfs(1);
		cout<<res<<endl;
	}
	return 0;
}
