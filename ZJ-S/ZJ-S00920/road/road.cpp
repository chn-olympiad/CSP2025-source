#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	char c=getchar();
	int x=0,f=1;
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+c-48,c=getchar();
	return x*f;
}
inline void print(const int x){
	if(x==0){putchar('0');return;}
	int t=x;
	if(t<0)t=-t,putchar('-');
	int num[40],len=0;
	while(t)num[len++]=t%10+48,t/=10;
	while(len--)putchar(num[len]);
}
const int N=1e4+15,INF=2e9;

struct edge{
	int u,v,w;
	bool operator<(const edge& t)const{
		return w<t.w;
	}
}e[1000005],g[110005];
int c[15];
int a[15][N];
int n,m;
int f[N];
int find(const int x){return f[x]==x?x:f[x]=find(f[x]);}
inline bool merge(int x,int y){x=find(x),y=find(y);if(x==y)return 0;f[x]=y;return 1;}
int b[N];

inline int solve(int X,int m){
	if(!X){
		int res=0;
		for(int i=1,cnt=0;i<=m&&cnt+1<n;i++)
			if(merge(e[i].u,e[i].v))res+=e[i].w,b[++cnt]=i;
		return res;
	}else{
		int res=0,cnt=0;
		for(int i=1;i<=m&&cnt+1<n+X;i++)
			if(merge(g[i].u,g[i].v))res+=g[i].w,++cnt;
		if(cnt+1<n+X)return -INF;
		return res;
	}
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read();
	int k=read();
	for(int i=1;i<=m;i++)
		e[i].u=read(),e[i].v=read(),e[i].w=read();
	sort(e+1,e+m+1);
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++)a[i][j]=read();
	}
	for(int i=1;i<=n;i++)f[i]=i;
	int ans=solve(0,m);
	for(int i=1;i<(1<<k);i++){
		for(int j=1;j<n;j++)g[j]=e[b[j]];
		int sum=0,X=0;
		int now=n;
		for(int j=1;j<=k;j++)
		if((i>>(j-1))&1){
			sum+=c[j];
			++X;
			for(int t=1;t<=n;t++)g[now++]=edge{n+X,t,a[j][t]};
		}
		sort(g+1,g+now);
		for(int j=1;j<=n+X;j++)f[j]=j;
		sum+=solve(X,now-1);
		if(sum<ans)ans=sum;
	}
	print(ans);
	return 0;
}
