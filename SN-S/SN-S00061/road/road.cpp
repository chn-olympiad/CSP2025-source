//SN-S00061  Liu Yuhe  School:Fengdong  kaodian:Binhe
#include<bits/stdc++.h>
using namespace std;
const int N=10005,M=1e6+5;
inline int read(){
	char c=getchar();int re=0;
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') re=(re<<1)+(re<<3)+(c-'0'),c=getchar();
	return re;
}inline void write(int x){
	if(x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}int n,m,k,cnt,cs[10],fa[N+10],sz[N+10],tp[11];
struct edge{int u,v,w;}ed[M],zz[M],eg[11][N];
inline bool cmp(edge x,edge y){return x.w<y.w;}
inline int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}inline void unite(int x,int y){
	x=find(x),y=find(y);
	if(sz[x]<sz[y]) swap(x,y);
	sz[x]+=sz[y],fa[y]=x;
}long long ans=1e18,sum;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
		ed[i]={read(),read(),read()};
	sort(ed+1,ed+m+1,cmp),tp[10]=1;
	for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
	for(int i=1;cnt<n-1;i++)
		if(find(ed[i].u)!=find(ed[i].v))
			eg[10][++cnt]=ed[i],unite(ed[i].u,ed[i].v);cnt=0;
	for(int i=0;i<k;i++){
		cs[i]=read();
		for(int j=1;j<=n;j++)
			eg[i][j]={j,n+i+1,read()};
		sort(eg[i]+1,eg[i]+n+1,cmp);
	}for(int s=0,cc=n;s<(1<<k);s++,cnt=sum=0,tp[10]=1,cc=n){
		for(int i=0;i<k;i++) if(s&(1<<i)) ++cc,sum+=cs[i],tp[i]=1;
		for(int i=1;i<=n+k;i++) fa[i]=i,sz[i]=1;
		for(int i=1;i<=n*(cc-n)+n-1&&cnt<cc-1;i++){
			int id=(tp[10]==n?-1:10);
			for(int j=0;j<k;j++) if((s&(1<<j))&&tp[j]<=n)
				if(id<0||eg[id][tp[id]].w>eg[j][tp[j]].w) id=j;
			ed[i]=eg[id][tp[id]++];
			if(sum+ed[i].w>=ans){sum=1e18;break;}
			if(find(ed[i].u)!=find(ed[i].v))
				++cnt,unite(ed[i].u,ed[i].v),sum+=ed[i].w;
		}ans=min(ans,sum);
	}return write(ans),0;
}
