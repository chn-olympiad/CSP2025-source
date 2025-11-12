#include<bits/stdc++.h>
#define MAXN 20004
#define MAXM 1000006
#define int long long
#define mod
#define look_time cerr<<(clock()-Time)*1.0/CLOCKS_PER_SEC<<"\n"
#define look_memory cerr<<abs(&M2-&M1)/1024.0/1024.0<<"\n";
using namespace std;

inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}

bool M1;
int n,m,k;
struct node{
	int u,v,w;
}E[MAXM],ed[MAXM],t[MAXM];
int c[20],a[20][MAXN];
int fa[MAXN];
const int inf=1e18;

int find(int x){
	if(x==fa[x]) return fa[x];
	return fa[x]=find(fa[x]);
}

void merge(int x,int y){
	x=find(x);y=find(y);
	if(x==y) return;
	fa[x]=y;
}

bool cmp(node aa,node bb){
	return aa.w<bb.w;
}

int Kruskal(int op,int nn,int mm){
	sort(E+1,E+1+mm,cmp);
	for(int i=1;i<=nn;i++) fa[i]=i;
	int res=0;
	int cnt=0;
	for(int i=1;i<=m;i++){
		int u=E[i].u,v=E[i].v,w=E[i].w;
		if(find(u)!=find(v)){
			merge(u,v);
			res+=w;
			if(op) t[++cnt]=E[i];
		}
	}
	return res;
}

bool M2;

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int Time=clock();
	n=read();m=read();k=read();
	int u,v,w;
	for(int i=1;i<=m;i++){
		u=read();v=read();w=read();
		E[i]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++) a[i][j]=read();
	}
	int ans=Kruskal(1,n,m);
	for(int i=1;i<n;i++) E[i]=t[i];
	for(int s=0;s<(1<<k);s++){
		for(int i=1;i<n;i++) E[i]=t[i];
		int cntn=n,cntm=n-1,res=0;
		for(int i=1;i<=k;i++){
			if(s&(1<<(i-1))){
				res+=c[i];
				cntn++;
				for(int j=1;j<=n;j++){
					E[++cntm]=(node){cntn,j,a[i][j]};
				}
			}
		}
		int tmp=Kruskal(0,cntn,cntm);
		res+=tmp;
		ans=min(ans,res);
	}
	printf("%lld\n",ans);
	look_memory;
	look_time;
	return 0;
}
