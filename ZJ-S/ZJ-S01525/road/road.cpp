#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e4+5;
const int M=1e6+6;
const int K=15;

struct DSU{
	unsigned s[N+K];
	unsigned siz[N+K];
	void initset(unsigned n){
		for(unsigned i=1;i<=n;i++){
			s[i]=i;
			siz[i]=1;
		}
	}
	unsigned findset(unsigned x){
		if(x!=s[x]){
			s[x]=findset(s[x]);
			siz[x]=siz[s[x]]+1;
		}
		return s[x];
	}
	void mergeset(unsigned u,unsigned v){
		u=findset(u);v=findset(v);
		if(u==v) return;
		if(siz[u]<siz[v]) swap(u,v);
		s[v]=u;
		siz[u]=max(siz[u],siz[v]+1);
	}
};

DSU dsu;

struct Edge{
	unsigned u,v;
	unsigned w;
}edge[M];
Edge useful[N];

bool cmp_edge(Edge i,Edge j){
	return i.w<j.w;
}

unsigned c[K];
unsigned a[K][N];//a[i][j] : the ith town to jth city

Edge newedge[K*N];
unsigned edgecnt=0;

unsigned n,m;

unsigned long long kruskal(unsigned n){
	unsigned cnt=0;
	dsu.initset(n);
	unsigned long long ret=0;
	for(unsigned i=0;i<m && cnt<n-1;i++){
		unsigned u=edge[i].u,v=edge[i].v;
		if(dsu.findset(u)==dsu.findset(v)) continue;
		dsu.mergeset(u,v);
		useful[cnt++]=edge[i];
		ret+=edge[i].w;
	}
	return ret;
}

unsigned k;

unsigned long long kruskal2(unsigned siz){
	unsigned cnt=0;
	dsu.initset(n+k);
	unsigned long long ret=0;
	unsigned i=0,j=0;
	while(cnt<siz-1){
		Edge cur;
		if(i>=n && j>=edgecnt){
			return ret;
		}
		if(i==n) cur=newedge[j++];
		else if(j==edgecnt) cur=useful[i++];
		else if(useful[i].w<newedge[j].w) cur=useful[i++];
		else cur=newedge[j++];
		int u=cur.u,v=cur.v;
//		cerr<<"cur "<<u<<" <-> "<<v<<" w= "<<cur.w<<"\n";
		if(dsu.findset(u)==dsu.findset(v)) continue;
		dsu.mergeset(u,v);
		ret+=cur.w;
		cnt++;
	}
	return ret;
}

unsigned qread(){
	unsigned x=0;
	char ch=getchar();
	while(ch<'0' || ch>'9') ch=getchar();
	while(ch>='0' && ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=qread();m=qread();k=qread();
	for(unsigned i=0;i<m;i++){
		unsigned u,v,w;
		u=qread();v=qread();w=qread();
//		scanf("%d%d%d",&u,&v,&w);
		edge[i].u=u;edge[i].v=v;
		edge[i].w=w;
	}
	sort(edge,edge+m,cmp_edge);
	for(unsigned i=0;i<k;i++){
		c[i]=qread();
//		scanf("%d",&c[i]);
		for(unsigned j=1;j<=n;j++){
			a[i][j]=qread();
//			scanf("%d",&a[i][j]);
		}
	}
	unsigned long long ans=kruskal(n);
	for(unsigned s=1;s<(1u<<k);s++){
		unsigned long long ret=0;
		edgecnt=0;
		unsigned cntnode=0;
		for(unsigned i=0;i<k;i++){
			if(s&(1<<i)){
				ret+=c[i];
				cntnode++;
				for(unsigned u=1;u<=n;u++){
					newedge[edgecnt++]={i+n+1,u,a[i][u]};
				}
			}
		}
		sort(newedge,newedge+edgecnt,cmp_edge);
		ret+=kruskal2(n+cntnode);
//		cerr<<s<<" : "<<ret<<"\n";
		ans=min(ans,ret);
	}
	printf("%llu\n",ans);
}
