#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
inline int re(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
const int N=505;
int n,m;
int d[N];
int c[N];
int a[N];
int vis[N];
int ans;
int fac[N];
inline void dfs(int k,int cnt){
	if(cnt>=m){
		ans=(ans+fac[n-k+1])%mod;
		return;
	}
	if(n-k+1+cnt<m)return;
	if(k==n+1)return;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			a[k]=i;
			if(d[k]&&c[i]>k-cnt-1)dfs(k+1,cnt+1);
			else dfs(k+1,cnt);
			vis[i]=0;
		}
	}
}
inline void inits(){
	fac[1]=fac[0]=1;
	for(int i=2;i<N;i++)fac[i]=fac[i-1]*i%mod;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=re(),m=re();
	inits();
	for(int i=1;i<=n;i++){
		char cc;cin>>cc;
		d[i]=cc-'0';
	}
	for(int i=1;i<=n;i++)c[i]=re();
	dfs(1,0);
	cout<<ans;
	return 0;
}


