#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1e18+10
inline int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')	f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')	x=x*10+ch-'0',ch=getchar();
	return x*f;
}
inline void write(int x){
	if(x<0)	x=-x,putchar('-');
	if(x>9)	write(x/10);
	putchar(x%10+'0');
	return;
}
int n,m,k;
struct Murasame{
	int u,v,w,id;
}e[52000001];
int a[11][10001];
int u[1000001],v[1000001],w[1000001];
int c[11],ans=0;
int fa[10001];
bool cmp(Murasame x,Murasame y){return x.w<y.w;}
void init(){for(int i=1;i<=n;i++)	fa[i]=i;}
int find(int x){
	if(x==fa[x])	return x;
	return fa[x]=find(fa[x]);
}
void kruskal(){
	int num=1;
	for(int i=1;i<=m;i++){
		if(num==n)	break;
		int u=e[i].u,v=e[i].v,w=e[i].w;
		int fu=find(u);
		int fv=find(v);
		if(fu==fv)	continue;
		ans+=w,fa[fa[u]]=v,num++;
	}
}
void solve1(){
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
			for(int x=j+1;x<=n;x++){
				if(x==j)	continue;
				e[++m].u=j,e[m].v=x,e[m].w=a[i][j]+a[i][x];
			}
	sort(e+1,e+1+m,cmp);
	kruskal();
	write(ans);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	init();
	for(int i=1;i<=m;i++)	e[i].id=0,e[i].u=read(),e[i].v=read(),e[i].w=read(),u[i]=e[i].u,v[i]=e[i].v,w[i]=e[i].w;
	int cnt=0;
	for(int i=1;i<=k;i++){
		c[i]=read();
		if(c[i]==0)	cnt++;
		for(int j=1;j<=n;j++)	a[i][j]=read();
	}	
	if(k==0){
		sort(e+1,e+1+m,cmp);
		kruskal();
		write(ans);
		return 0;
	}
	if(cnt==k){
		solve1();
		return 0;
	}
	sort(e+1,e+1+m,cmp);
	kruskal();
	int s=ans;
	for(int i=1;i<=k;i++){
		ans=0;ans+=c[i];
		int t=m;
		for(int i=1;i<=m;i++)	e[i].u=u[i],e[i].v=v[i],e[i].w=w[i];
		for(int j=1;j<=n;j++)
			for(int x=j+1;x<=n;x++){
				if(x==j)	continue;
				e[++t].u=j,e[t].v=x,e[t].w=a[i][j]+a[i][x];
			}
		sort(e+1,e+1+t,cmp);
		init();kruskal();
		s=min(s,ans);
	}
	write(s);
}