#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;
const int N=1e4+5;
const int M=1e6+5; 
const int K=20;
int read(){
	int x=0,f=1;char ch=getchar();
	while('0'>ch||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,k,cnt,c[K],fa[N+K];
pair<int,int>e[M<<1],E[M],usE[M],tmp[M],a[K][N];
int findfa(int x){return fa[x]==x?x:fa[x]=findfa(fa[x]);}
bool merge(int x,int y){
	x=findfa(x);
	y=findfa(y);
	if(x==y)return false;
	fa[x]=y;
	return true;
}
void init(){
	n=read();m=read();k=read();
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
		e[i]={read(),read()},E[i]={read(),i};
	sort(E+1,E+m+1);
	ll ans=0;
	for(int i=1,j;i<=m;i++){
		 j=E[i].se;
		 if(merge(e[j].fi,e[j].se))
		 	E[++cnt]=E[i],ans+=E[i].fi;
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			e[++m]={n+i,j};
			a[i][j]={read(),m};
		}
		sort(a[i]+1,a[i]+n+1);
	}
	return;
}
ll ans=0x3f3f3f3f3f3f3f3f;
void calc(int con,ll ser=0){
	int res=cnt;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=res;i++)usE[i]=E[i];
	for(int i=0;i<k;i++)
		if(con>>i&1){
			fa[n+i+1]=n+i+1;
			ser+=c[i+1];
			if(ser>=ans)return;
			for(int j=1;j<=res;j++)tmp[j]=usE[j];
			int j1=1,j2=1,tot=0;
			while(j1<=res&&j2<=n){
				if(tmp[j1].fi<a[i+1][j2].fi)usE[++tot]=tmp[j1++];
				else usE[++tot]=a[i+1][j2++]; 
			}
			while(j1<=res)usE[++tot]=tmp[j1++];
			while(j2<=n)usE[++tot]=a[i+1][j2++];
			res=tot; 
		}
	for(int i=1,j;i<=res;i++){
		j=usE[i].se;
		if(merge(e[j].fi,e[j].se))
			ser+=usE[i].fi;
		if(ser>=ans)return;
	}
	ans=ser;
	return;
}
void solve(){
	for(int i=0;i<1<<k;i++)calc(i);
	printf("%lld\n",ans);
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	init();
	solve();
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/