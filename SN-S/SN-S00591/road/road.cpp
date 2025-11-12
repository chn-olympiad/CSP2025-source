#include<bits/stdc++.h>
#define M 1000005
#define N 10005
#define ll long long
using namespace std;
struct IO{
	static const int siz=(1<<20);
	char buf[siz],*p1,*p2;
	char gc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,siz,stdin),p1==p2)?EOF:*p1++;}
	IO &operator >>(int &x){
		x=0;char c=gc();
		while(!isdigit(c))	c=gc();
		while(isdigit(c))	x=(x<<1)+(x<<3)+(c^'0'),c=gc();
		return *this;
	}
}fin;
int n,m,k,c[N],fa[N],pos[15],tot;
ll ans,cst;
struct node{
	int u,v,w;
}e[M],a[15][N];
int find(int u){
	if(fa[u]==u)	return u;
	return fa[u]=find(fa[u]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	fin>>n>>m>>k;
	for(int i=1;i<=n;i++)	fa[i]=i;
	for(int i=1,u,v,w;i<=m;i++)	fin>>u>>v>>w,e[i]={u,v,w};
	sort(e+1,e+m+1,[=](node x,node y){return x.w<y.w;});
	for(int i=1,cnt=0;i<=m;i++){
		int u=find(e[i].u),v=find(e[i].v);
		if(u==v)	continue;
		fa[v]=u,ans+=e[i].w,e[++cnt]=e[i];
	}
	for(int i=1;i<=k;i++){
		fin>>c[i];
		for(int j=1,x;j<=n;j++)	fin>>x,a[i][j]={n+i,j,x};
		sort(a[i]+1,a[i]+n+1,[=](node x,node y){return x.w<y.w;});
	}
	for(int s=1;s<(1<<k);s++){
		for(int i=1;i<=n+k;i++)	fa[i]=i;
		cst=0,tot=n-1,pos[0]=1;
		for(int i=1;i<=k;i++){
			pos[i]=n+1;
			if(!((s>>i-1)&1))	continue;
			pos[i]=1,cst+=c[i],tot++;
		}
		while(tot){
			node mn={0,0,0x3f3f3f3f};
			if(pos[0]<n)	mn=e[pos[0]];
			int p=0;
			for(int i=1;i<=k;i++){
				if(pos[i]>n)	continue;
				if(a[i][pos[i]].w<mn.w)	mn=a[i][pos[i]],p=i;
			}
			int u=find(mn.u),v=find(mn.v);
			pos[p]++;
			if(u==v)	continue;
			cst+=mn.w,fa[v]=u,tot--;
		}
		ans=min(ans,cst);
	}
	cout<<ans;
	return 0;
}
