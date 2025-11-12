#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+10,M=1e6+10,K=12,P=1e3+30;
inline int read(){
    int x=0,fg=0;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') fg=1; ch=getchar();}
    while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
    return fg?(~(x-1)):x;
}
int n,m,k,mp[K][N],lg[P];
int fa[N],l[N]; ll ans,sum[P];
struct node{int u,v,w;};
node a[M],b[P][N],c[M];
bool cmp(node x,node y){return x.w<y.w;}
int fid(int x){return x==fa[x]?x:fa[x]=fid(fa[x]);}
void mg(int x,int y){x=fid(x),y=fid(y),fa[x]=y;}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read(),m=read(),k=read();
    for(int i=0;i<=k;i++) lg[1<<i]=i;
    for(int i=1;i<=m;i++)
    	a[i]={read(),read(),read()};
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
    	int x=a[i].u,y=a[i].v;
    	if(fid(x)==fid(y)) continue;
    	b[0][++l[0]]=a[i],mg(x,y),ans+=a[i].w;
	}
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++)
			mp[i][j]=read();
	for(int i=1;i<(1<<k);i++){
		int x=i&-i,y=i^x,z=lg[x];
		int ip=0,cur=0;ll as=0;
		for(int j=1;j<=l[y];j++)
			c[++cur]=b[y][j];
		sum[i]=sum[y]+mp[z+1][0];
		for(int j=1;j<=n;j++)
			c[++cur]={n+z+1,j,mp[z+1][j]};
		sort(c+1,c+cur+1,cmp);
		for(int j=1;j<=n+k;j++) fa[j]=j;
		for(int j=1;j<=cur;j++){
			int ax=c[j].u,ay=c[j].v;
			if(fid(ax)==fid(ay)) continue;
			b[i][++l[i]]=c[j],mg(ax,ay),as+=c[j].w;
		}
		ans=min(ans,as+sum[i]);
	}
	printf("%lld\n",ans);
    return 0;
}


