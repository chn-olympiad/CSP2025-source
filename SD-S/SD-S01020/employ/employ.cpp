#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
constexpr ll N=505,mod=998244353;
ll n,m,ans=0,a[N],c[N],p[N],fac[N];bool vis[N];
char s[N];
inline ll reads(){
	char c=getchar();
	ll x=0,f=1;
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c-'0');
		c=getchar();
	}return x*f;
}inline void files(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
}
bool check(){
	ll cnt=0,res=0;
	for(ll i=1;i<=n;i++){
		if(cnt>=c[p[i]]) continue;
		if(!a[i]) cnt++;
		else res++;
	}return res>=m;
}
void dfs(ll idx){
	if(idx>n){
		ans+=check();
		return;
	}
	for(ll i=1;i<=n;i++){
		if(vis[i]) continue;
		p[idx]=i,vis[i]=1;
		dfs(idx+1);
		vis[i]=0,p[idx]=0;
	}
}
signed main(){//file LL MLE WA
	files();
	bool flg=0;
	scanf("%lld%lld%s",&n,&m,s+1);
	for(ll i=1;i<=n;i++){
		a[i]=s[i]-'0';
		if(!a[i]) flg=1;
	}for(ll i=1;i<=n;i++) c[i]=reads();
	if(flg){
		fac[0]=1;
		for(ll i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
		printf("%lld\n",fac[n]);
	}
	else{
		dfs(1);
		printf("%lld\n",ans);
	}
	return 0;
}
/*
4 2
111
1 1 2 3
*/
