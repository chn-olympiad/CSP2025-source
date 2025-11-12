#include<bits/stdc++.h>
using namespace std;
int read(){
	int ans=0;
	char c=' ';
	while(!('0'<=c&&c<='9')) c=getchar();
	while('0'<=c&&c<='9'){
		ans=ans*10+c-'0';
		c=getchar();
	}
	return ans;
}
int n,m,k;
struct Edge{
	int u,v,w;
	bool operator < (const Edge &A) const{
		return w<A.w;
	}
}edges[2000005];
int fa[10005];
int getrt(int u){
	if(fa[u]==u) return u;
	return fa[u]=getrt(fa[u]);
}
int c[10],a[10][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++) edges[i].u=read(),edges[i].v=read(),edges[i].w=read();
	for(int i=1;i<=n+k;i++) fa[i]=i;
	if(m<=1e5&&k<=5){
		for(int i=1;i<=k;i++){
			c[i]=read();
			for(int j=1;j<=n;j++){
				a[i][j]=read();
			}
		}
		int ccf=m;
		long long mi=1e18;
		for(int i=0;i<=(1<<k)-1;i++){
			m=ccf;
			long long ans=0;
			for(int j=1;j<=k;j++){
				if((i>>(j-1))&1){
					for(int z=1;z<=n;z++){
						m++;
						edges[m]=Edge{j+n,z,a[j][z]};
					}
					ans+=c[j];
				}
			}
			for(int j=1;j<=n+k;j++) fa[j]=j;
			sort(edges+1,edges+m+1);
			for(int j=1;j<=m;j++){
				int fx=getrt(edges[j].u);
				int fy=getrt(edges[j].v);
				if(fx==fy) continue;
				fa[fx]=fy;
				ans+=edges[j].w;
			}
//			printf("%lld\n",ans);
			mi=min(mi,ans);
			int cnt=1;
			for(int j=1;j<=m;j++){
				if(edges[j].u<=n) edges[cnt]=edges[j],cnt++;
			}
		}
		printf("%lld\n",mi);
		return 0;
	}
	for(int i=n+1;i<=n+k;i++){
		int x;
		x=read();
		for(int j=1;j<=n;j++){
			m++;
			edges[m].w=read();
			edges[m].u=i;
			edges[m].v=j;
		}
	}
	sort(edges+1,edges+m+1);
	long long ans=0;
	for(int i=1;i<=m;i++){
		int fx=getrt(edges[i].u);
		int fy=getrt(edges[i].v);
		if(fx==fy) continue;
		fa[fx]=fy;
		ans+=edges[i].w;
	}
	printf("%lld\n",ans);
	return 0;
}
