#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mk mape_pair
using namespace std;
const int N=1e4+100,M=1e6+5;
struct Edge{
	int fr,to,v,ps;
	friend bool operator <(Edge x,Edge y){return x.v>y.v;}
}edge[M<<1];
priority_queue<Edge> q;
int n,m,k,c[N],vtr[1030][N],fa[N],siz[N],lg[M];
ll ans,sum,cnt,tot;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		ret=(ret<<3)+(ret<<1)+ch-'0';
		ch=getchar();
	}
	return ret*f;
}
void print(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>=10) print(x/10);
	putchar(x%10+'0');
}
bool cmp(Edge x,Edge y){return x.v<y.v;}
int get(int x){
	if(x==fa[x]) return x;
	return fa[x]=get(fa[x]);
}
ll solve(int vk){
	sum=cnt=0;tot=n;
	int lst=vk-(vk&(-vk)),pl=lg[vk&(-vk)];
	for(int i=0;i<k;i++) if(vk&(1<<i)) sum+=c[i+1],tot++;	
	for(int i=1;i<=n;i++) q.push(edge[pl*n+i+m]);
	for(int i=1;i<tot-1;i++) q.push(edge[vtr[lst][i]]);
	for(int i=1;i<=n+k;i++) fa[i]=i,siz[i]=1; 
	while(cnt<tot-1){
		Edge tp=q.top();q.pop();
		int gx=get(tp.fr),gy=get(tp.to);
		if(gx==gy) continue;
		if(siz[gx]<siz[gy]) swap(gx,gy);
		cnt++;sum+=tp.v;fa[gy]=gx;siz[gx]+=siz[gy];vtr[vk][cnt]=tp.ps;
	}
	while(q.size()) q.pop();
	return sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=2;i<M;i++) lg[i]=lg[i>>1]+1;
	for(int i=1;i<=m;i++) edge[i].fr=read(),edge[i].to=read(),edge[i].v=read();
	sort(edge+1,edge+m+1,cmp);
	for(int i=1;i<=n+k;i++) fa[i]=i,siz[i]=1;
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			int p=(i-1)*n+j+m;
			edge[p].ps=p;edge[p].fr=i+n;edge[p].to=j;edge[p].v=read();
		}
	}
	for(int i=1;i<=m;i++) edge[i].ps=i;
	for(int i=1;i<=m;i++){
		int gx=get(edge[i].fr),gy=get(edge[i].to);
		if(gx==gy) continue;
		if(siz[gx]<siz[gy]) swap(gx,gy);
		fa[gy]=gx;cnt++;ans+=edge[i].v;vtr[0][cnt]=i;siz[gx]+=siz[gy];
		if(cnt==n-1) break;
	}
	for(int i=1;i<(1<<k);i++) ans=min(ans,solve(i));
	printf("%lld",ans);
	return 0;
}
/*
5 8 3
2 5 3
4 2 0
2 4 7
5 2 7
5 3 9
1 3 7
5 4 5
4 5 4
1 7 2 5 6 0 
2 3 1 7 0 2 
3 3 3 4 8 8 
*/