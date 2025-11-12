#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int now=0,res=1;char c=getchar();
	while(!isdigit(c))res=(c=='-'?-1:1),c=getchar();
	while(isdigit(c))now=now*10+c-'0',c=getchar();
	return now*res;
}
const int N=1e4+30,M=1e6+10;
int fa[N],n,m,k;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
struct ed{int u,v,w;}edge[M],edge1[N*2];
bool cmp(ed x,ed y){return x.w<y.w;}
int c[15],a[15][N];
long long ans[1025],beg[1025]; 
//vector<pair<int,int> >a[N];
vector<ed>f[1025];
void print(int x){
	for(auto v:f[x])printf("{%d,%d,%d}\n",v.u,v.v,v.w);
	printf("%lld %lld\n",ans[x],beg[x]);puts("");
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
		edge[i]=(ed){read(),read(),read()};
	sort(edge+1,edge+m+1,cmp);
	for(int i=1;i<=m;i++){
		int u=edge[i].u,v=edge[i].v,w=edge[i].w;
		if((u=find(u))==(v=find(v)))continue;
		fa[u]=v;f[0].push_back(edge[i]);ans[0]+=w;
	}
	for(int i=1;i<=k;i++){c[i]=read();
	for(int j=1;j<=n;j++)a[i][j]=read();}
	for(int i=1;i<(1<<k);i++){int lst=0;
		for(int j=1;j<=10;j++)if(i&(1<<(j-1))){lst=j;break;}
		int p=i^(1<<(lst-1)),tot=0;
		for(auto v:f[p])edge1[++tot]=v;
		for(int j=1;j<=n;j++)edge1[++tot]=(ed){lst+n,j,a[lst][j]};
		for(int j=1;j<=n+10;j++)fa[j]=j;
		sort(edge1+1,edge1+tot+1,cmp);
		beg[i]=beg[p]+c[lst];
		for(int j=1;j<=tot;j++){
			int u=edge1[j].u,v=edge1[j].v,w=edge1[j].w;
			if((u=find(u))==(v=find(v)))continue;
			fa[u]=v;f[i].push_back(edge1[j]);ans[i]+=w;
		}
	}
	long long _ans=1e18;
	for(int i=0;i<(1<<k);i++){
		_ans=min(_ans,beg[i]+ans[i]);
	}printf("%lld\n",_ans);
	return 0;
}
