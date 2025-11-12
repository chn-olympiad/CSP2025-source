#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,m1,k,fa[10005],c[15],now,top;
pair<int,int>a[15][10005];
long long cnt,ans=1e18;
struct Seg{
	int x,y,w;
}v[1000005],u[20005],tmp[2][20005];
bool cmp(Seg x,Seg y){
	return x.w<y.w;
}
int getfa(int x){
	if(fa[x]==x)return x;
	return fa[x]=getfa(fa[x]);
}
inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch&15);
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m1=read(),k=read();
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m1;i++)v[i].x=read(),v[i].y=read(),v[i].w=read();
	sort(v+1,v+m1+1,cmp);
	for(int i=1;i<=m1;i++){
		int tx=v[i].x,ty=v[i].y,fx=getfa(tx),fy=getfa(ty);
		if(fx!=fy){
			fa[fx]=fy;
			cnt=cnt+v[i].w,u[++m]=v[i];
		}
	}
	ans=min(ans,cnt);
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1,x;j<=n;j++){
			x=read();
			a[i][j]=make_pair(x,j);
		}
		sort(a[i]+1,a[i]+n+1);
	}
	for(int sta=0;sta<=(1<<k)-1;sta++){
		for(int i=1;i<=m;i++)tmp[!now][i]=u[i];
		for(int i=1;i<=n+k;i++)fa[i]=i;
		top=m;
		for(int i=1;i<=k;i++)if(sta&(1<<i-1)){
			int x=1,y=1,t=0;
			while(x<=n&&y<=top){
				if(a[i][x].first<=tmp[!now][y].w)tmp[now][++t]=(Seg){a[i][x].second,n+i,a[i][x].first},++x;
				else tmp[now][++t]=tmp[!now][y++];
			}
			while(x<=n)tmp[now][++t]=(Seg){a[i][x].second,n+i,a[i][x].first},++x;
			while(y<=top)tmp[now][++t]=tmp[!now][y++];
			now^=1,top=t;
		}
		now^=1,cnt=0;
		for(int i=1;i<=k;i++)if(sta&(1<<i-1))cnt=cnt+c[i];
		for(int i=1;i<=top;i++){
			int tx=tmp[now][i].x,ty=tmp[now][i].y,fx=getfa(tx),fy=getfa(ty);
			if(fx!=fy){
				fa[fx]=fy;
				cnt=cnt+tmp[now][i].w;
			}
		}
		ans=min(ans,cnt);
	}
	cout<<ans;
	return 0;
}