#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int f=1,k=0;char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-') f=-1,c=getchar();
	while(isdigit(c)) k=k*10+(c-'0'),c=getchar();
	return f*k;
}
const int N=2e6+10,M=1e3+10;
int n,m,k,ans,cnt,tot,flag,c[15],a[15][M],fa[M],g[M][M];
struct node{
	int u,v,w;
}t[N];
bool cmp(node a,node b){
	return a.w<b.w;
}
int find(int x){
	if(fa[x]==x) return fa[x];
	return fa[x]=find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();flag=1;
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		t[i]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		c[i]=read();
		if(c[i]) flag=0;
		for(int j=1;j<=n;j++) a[i][j]=read();
	}
	if(k==0){
		sort(t+1,t+1+m,cmp);
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=m;i++){
			int fx=find(t[i].u),fy=find(t[i].v);
			if(fx!=fy){
				fa[fx]=fy;
				ans+=t[i].w;
				cnt++;
			}
			if(cnt==n-1){
				cout<<ans;
				return 0;
			}
		}
	}else if(flag&&n<=1010){
		memset(g,0x3f,sizeof(g));tot=m;
		for(int kk=1;kk<=k;kk++){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					g[i][j]=min(g[i][j],a[kk][i]+a[kk][j]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				t[++tot]={i,j,g[i][j]};
			}
		}
		for(int i=1;i<=n;i++) fa[i]=i;
		sort(t+1,t+1+tot,cmp);
		for(int i=1;i<=tot;i++){
			int fx=find(t[i].u),fy=find(t[i].v);
			if(fx!=fy){
				fa[fx]=fy;
				ans+=t[i].w;
				cnt++;
			}
			if(cnt==n-1){
				cout<<ans;
				return 0;
			}
		}
	}
	return 0;
}