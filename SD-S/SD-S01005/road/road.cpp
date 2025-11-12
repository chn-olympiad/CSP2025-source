#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+5;

int read(){
	int s=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s*f;
} 

struct edge{
	int v,nxt,w;
}e[N<<1];
int hd[N],cnte;

void adde(int u,int v){
	e[++cnte].v=v;
	e[cnte].nxt=hd[u];
	hd[u]=cnte;
}

struct edges{
	int u,v,w;
}es[N];

bool cmp(edges x,edges y){
	return x.w<y.w;
} 

int n,m,k;

int fat[N];
int find(int x){
	if(x==fat[x])return x;
	return fat[x]=find(x);
}

int ans;
int c[11],a[11][N];

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	n=read(),m=read(),k=read();
		for(int i=1;i<=n;i++)
			fat[i]=i;
		for(int i=1;i<=m;i++)
			es[i].u=read(),es[i].v=read(),es[i].w=read();
		sort(es+1,es+1+m,cmp);
		for(int i=1;i<=m;i++){
			int u=find(es[i].u),v=find(es[i].v);
			if(u==v)continue;
			fat[u]=v;
			ans+=e[i].w;
		}
		cout<<ans<<"\n";
	
	return 0;
}
