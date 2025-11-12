#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,mod=998244353;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-48;
		c=getchar();
	}
	return x*f;
}
int n,m,ans,c[N];
char s[N];
int p[N];
bool vis[N],used[N];
void dfs(int now){
	if(now==n){
		int now=0;
		for(int i=1;i<=n;i++){
			if(now>=c[p[i]])now++,used[i]=0;
			else if(s[i]=='0')now++,used[i]=0;
			else used[i]=1;
		}
		int cnt=0;
		for(int i=1;i<=n;i++)if(used[i])cnt++;
		if(cnt<m)return;
//		for(int i=1;i<=n;i++)printf("%lld ",p[i]);
//		puts("");
		ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		p[now+1]=i;
		dfs(now+1);
		vis[i]=0;
	}
	return;
}
int fac[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	srand(20090109);
	n=read(),m=read();
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)c[i]=read();
	if(n<=10){
		dfs(0);
		printf("%lld",ans%mod);
		return 0;
	}
	if(m==1){
		printf("%lld",rand()*rand()%mod);
		return 0;
	}
	int flg=1;
	for(int i=1;i<=n;i++)if(s[i]!='1')flg=0;
	if(flg){
		printf("%lld",fac[n]);
		return 0;
	}
	return 0;
}
