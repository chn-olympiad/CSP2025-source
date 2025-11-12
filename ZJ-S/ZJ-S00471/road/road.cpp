#include<iostream>
#include<algorithm>
#define int long long
const int K=20;
const int N=1e4+10;
const int M=1e6+10;
const int inf=1e18;
using namespace std;
namespace IO{
	int read(){
		int x=0,f=1;char ch=getchar();
		while(ch<'0'||ch>'9'){
			if(ch=='-')f=-f;
			ch=getchar();
		}
		while(ch>='0'&&ch<='9'){
			x=x*10+ch-'0';
			ch=getchar();
		}return x*f;
	}
	void print(int x){
		if(x<0){
			x=-x;
			putchar('-');
		}
		if(x>9)print(x/10);
		putchar(x%10+'0');
	}
	void put(int x){print(x);putchar('\n');}
}using namespace IO;
int n,m,k,cnt,ans=inf,c[K],val[K][N],fa[N];
struct Node{int u,v,w;}a[M];
struct Edge{int u,v,w,s;}e[K*N];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void merge(int u,int v){
	u=find(u),v=find(v);
	fa[u]=v;
}
bool cmp(Node x,Node y){return x.w<y.w;}
bool cmp1(Edge x,Edge y){return x.w<y.w;}
int f[N],siz[N],S[K];
int fd(int x){
	if(f[x]==x)return x;
	return f[x]=fd(f[x]);
}
void mg(int u,int v){
	u=fd(u),v=fd(v);
	if(siz[u]>siz[v])swap(u,v);
	siz[v]+=siz[u];f[u]=v;
}
void dfs(int *S,int now,int sum){
	if(now>k){
		for(int i=1;i<=n+k;i++)f[i]=i,siz[i]=1;
		for(int i=1,j=0;i<=cnt;i++){
			int u=e[i].u,v=e[i].v,w=e[i].w;
			if(fd(u)==fd(v)||S[e[i].s]==0)continue;
			mg(u,v);sum+=w;j++;
			if(j==n+k-1)break;
		}ans=min(ans,sum);return;
	}
	S[now]=0;dfs(S,now+1,sum);
	S[now]=1;dfs(S,now+1,sum+c[now]);S[now]=0;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();S[0]=1;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)	
		a[i].u=read(),a[i].v=read(),a[i].w=read();
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		int u=a[i].u,v=a[i].v,w=a[i].w;
		if(find(u)==find(v))continue;
		merge(u,v);e[++cnt]={u,v,w,0};
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++)val[i][j]=read(),e[++cnt]={i+n,j,val[i][j],i};
	}sort(e+1,e+cnt+1,cmp1);
	dfs(S,1,0);print(ans);
	return 0;
}
