#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<string>
#include<cstring>
#define r read()
using namespace std;
inline __int128 read(){
	__int128 x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch&15);ch=getchar();}
	return x*f;
}
const int N=5e6+10,maxn=1e5+10;
int n,m,k,tot;
int fa[N];
long long ans,a[maxn][15],c[maxn];
bool vis[N];
struct edge{
	int from,to;
	long long val;
}g[N];
void Add(int u,int v,long long w){
	g[++tot]={u,v,w};
}
bool cmp(edge x1,edge x2){
	return x1.val<x2.val;
}
int Find(int x){
	if(fa[x]==x) return x;
	return fa[x]=Find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=r,m=r,k=r;
	if(k==0){
		for(int i=1,u,v,w;i<=m;i++){
			u=r,v=r,w=r;
			Add(u,v,w);
		}
		sort(g+1,g+m+1,cmp);
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=m;i++){
			int x=g[i].from,y=g[i].to;
			int fx=Find(x),fy=Find(y);
			if(fx==fy)continue;
			fa[fx]=fy;
			ans+=g[i].val;
		}
		printf("%lld\n",ans);
		return 0;
	}
	for(int i=1,u,v,w;i<=m;i++){
		u=r,v=r,w=r;
		Add(u,v,w);
	}
	for(int i=1;i<=k;i++){
		c[i]=r;
		for(int j=1;j<=n;j++){
			a[j][i]=r;
		}
	}
	if(n<=1e3){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				for(int z=1;z<=n;z++){
					if(j==z)continue;
					Add(j,z,a[j][i]+a[z][i]);
				}
			}
		}
		sort(g+1,g+m+k+1,cmp);
		for(int i=1;i<=m;i++){
			int x=g[i].from,y=g[i].to;
			int fx=Find(x),fy=Find(y);
			if(fx==fy)continue;
			fa[fx]=fy;
			ans+=g[i].val;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
