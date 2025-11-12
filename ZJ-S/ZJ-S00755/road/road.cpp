#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+5,M=1e6+5;
int n,m,K;
struct Edge{
	int u,v,w;
	bool operator<(const Edge &x)const{
		return w<x.w;
	}
}a[M],e[N*10];
int fa[N];
int c[15][N];
ll ans=1e18;
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int read(){
	int x=0;
	char ch=getchar();
	while((ch<'0')|(ch>'9'))ch=getchar();
	while((ch>='0')&(ch<='9'))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	return x;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();K=read();
	for(int i=1;i<=m;i++){
		a[i].u=read();a[i].v=read();a[i].w=read();
//		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
	}
	for(int i=1;i<=K;i++){
		for(int j=0;j<=n;j++){
			c[i][j]=read();
//			scanf("%d",&c[i][j]);
		}
	}
	sort(a+1,a+m+1);
	for(int i=0;i<(1<<K);i++){
		int cnt=0;
		ll now=0;
		for(int j=0;j<K;j++){
			if((i>>j)&1){
				now+=c[j+1][0];
				for(int k=1;k<=n;k++)e[++cnt]=(Edge){k,j+n+1,c[j+1][k]};
			}
		}
		sort(e+1,e+cnt+1);
		int j=1,k=1;
		int ce=0;
		for(int p=1;p<=n+K;p++)fa[p]=p;
		int ru,rv;
		while((j<=m)&(k<=cnt)&(ce<n+cnt-1)&(now<ans)){
			if(a[j].w<e[k].w){
//				u=a[j].u,v=a[j].v;
				ru=find(a[j].u),rv=find(a[j].v);
				if(ru^rv)fa[ru]=rv,ce++,now+=a[j].w;
				j++;
			}else{
//				u=e[k].u,v=e[k].v;
				ru=find(e[k].u),rv=find(e[k].v);
				if(ru^rv)fa[ru]=rv,ce++,now+=e[k].w;
				k++;
			}
		}
		while((j<=m)&(ce<n+cnt-1)&(now<ans)){
//			u=a[j].u,v=a[j].v;
			ru=find(a[j].u),rv=find(a[j].v);
			if(ru^rv)fa[ru]=rv,ce++,now+=a[j].w;
			j++;
		}
		while((k<=cnt)&(ce<n+cnt-1)&(now<ans)){
//			u=e[k].u,v=e[k].v;
			ru=find(e[k].u),rv=find(e[k].v);
			if(ru^rv)fa[ru]=rv,ce++,now+=e[k].w;
			k++;
		}
		ans=(ans>now?now:ans);
	}
	cout<<ans<<'\n';
	return 0;
}

