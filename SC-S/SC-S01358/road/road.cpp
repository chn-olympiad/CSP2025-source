#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int in(){
	int s=1,k=0;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') s=-1;c=getchar();}
	while('0'<=c&&c<='9'){k=(k<<1)+(k<<3)+(c^48);c=getchar();}
	return k*s;
}
void out(ll x){
	if(x<0) x=-x,putchar('-');
	if(x>9) out(x/10);
	putchar(x%10^48);
}
const int MAXN=1e3+4;
const int inf=INT_MAX>>1;
int fa[MAXN];
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
struct Edge{
	int u,v,w;
}edge[MAXN*MAXN];
//struct EDGE{
//	int u,v,w;
//	int cost;
//}edge2[MAXN*15];
bool operator <(const Edge &x,const Edge &y){
	return x.w<y.w;
}
int dis[MAXN][MAXN];
int country[15];
int w[15][MAXN];
int cnt=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	n=in(); m=in(); k=in();
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=inf;
	for(int i=1,a,b,c;i<=m;i++){
		a=in(); b=in(); c=in();
		dis[a][b]=min(dis[a][b],c);
		dis[b][a]=dis[a][b];
	}
	ll sum=0;
	for(int i=1;i<=k;i++){
		country[i]=in();
		for(int j=1;j<=n;j++){
			w[i][j]=in();
		}
		for(int j=1;j<n;j++){
			for(int k=j+1;k<=n;k++){
				if(dis[j][k]>=w[i][j]+w[i][k]+country[i]){
					dis[j][k]=w[i][j]+w[i][k];
					dis[k][j]=dis[j][k];
					sum+=country[i];
					country[i]=0;
				}
			}
		}
	}
	for(int i=1;i<n;i++) for(int j=i+1;j<=n;j++) edge[++cnt]={i,j,dis[i][j]};
	ll ans=0;
	int tot=0;
	sort(edge+1,edge+1+cnt);
	for(int i=1;i<=cnt;i++){
		int u=edge[i].u; int v=edge[i].v;
		int fau=find(u); int fav=find(v);
		if(fau==fav) continue;
		fa[fau]=fav;
		ans+=edge[i].w;
		tot++;
		if(tot==n-1) break;
	}
	out(ans+sum);
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
