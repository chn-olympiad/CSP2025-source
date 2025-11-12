#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
#define re register
using namespace std;
const int N=1010;
const int Mod=998244353;
inline int read(int &x){
	int k=0,f=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		k=(k<<3)+(k<<1)+(c^'0');
		c=getchar();
	}
	x=k*f;
}
int n,m,ans=0;
int a[N]={0},su[N]={0};
string x;
bool vis[N]={0};
void dfs(int dep,int k){
	if(n-k<m) return ;
	if(dep>n){
		if(n-k>=m){
			ans=(ans+1)%Mod;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		if(k<a[i]&&x[dep-1]=='1'){
			dfs(dep+1,k);
		}
		else{
		    dfs(dep+1,k+1);	
		}
		vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>x;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}
