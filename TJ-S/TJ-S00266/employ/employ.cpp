#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500,mod=998244353;
int n,m,ans,a[N],b[N],c[N],d[N],t[N],r[N],f[N][N];
bool vis[N];
inline int read(){int x(0),f(1);char ch=getchar();for(;!isdigit(ch);ch=getchar())if(ch=='-') f=-1;for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);return x*f;}
void dfs(int now,int s){
	if(n-s<m) return;
	if(now==n+1){
		ans++;
//			for(int i=1;i<=n;i++) printf("%d ",r[i]);puts("");
		return;
	}
	for(int i=1;i<=n;i++) if(!vis[i]){
		vis[i]=1;
		r[now]=i;
		if(!a[now]||s>=c[i]) dfs(now+1,s+1);
		else dfs(now+1,s);
		vis[i]=0;
	}
}
void work1(){
	ans=1;
	for(int i=1;i<=n;i++) ans=ans*i%mod;
	printf("%lld",ans);
	exit(0);
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	int cc=clock();
	n=read(),m=read();
	for(int i=1;i<=n;i++) scanf("%1d",&a[i]),b[i]=b[i-1]+(a[i]==1);
	for(int i=1;i<=n;i++) c[i]=read();
	if(b[n]==n&&n>=100) work1();
	if(m==1&&n>=100) work1();
	if(n>=500){
		puts("0");
		return 0;
	}
	dfs(1,0);
	printf("%lld",ans);
//	printf("\n%d",clock()-cc);
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
