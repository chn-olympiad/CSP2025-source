#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M=1000002,N=10002;
struct node{
	int u,v,w;
}e[M];
bool cmp(node a,node b){
	return a.w<b.w;
}
int fa[N],c[N],t[11][N],mx=-1;
int n,m,k;
long long d[1002][1002],dis[N];
bool vis[N];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]); 
} 
long long prim(){
	long long ans=0;
	for(int i=1;i<=n;i++) dis[i]=1e18,vis[i]=0;
	dis[1]=0;
	for(int i=1;i<=n;i++){
		int u=-1,mn=1e18;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&dis[j]<mn){
				mn=dis[j];
				u=j;
			}
		}
		if(u==-1) return 1e18;
		ans+=dis[u];
		vis[u]=1;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&d[u][j]<dis[j]) dis[j]=d[u][j];
		}
	} 
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); 
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>t[i][j];
		mx=max(mx,c[i]);
	}
	if(k==0){
		long long ans=0,cnt=0;
		sort(e+1,e+m+1,cmp);
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=m;i++){
			int u=find(e[i].u),v=find(e[i].v);
			if(u==v) continue;
			ans+=e[i].w;
			cnt++;
			fa[u]=v;
			if(cnt==n-1) break;
		}
		cout<<ans<<endl;
	} 
	else if(mx==0){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) d[i][j]=1e18;
		for(int i=1;i<=m;i++)
			d[e[i].u][e[i].v]=d[e[i].v][e[i].u]=min(d[e[i].u][e[i].v],(long long)e[i].w);
		for(int i=1;i<=n;i++){
			d[i][i]=0;
			for(int j=i+1;j<=n;j++){
				long long mn=1e18;
				for(int l=1;l<=k;l++) mn=min(mn,(long long)t[l][i]+t[l][j]);
				d[i][j]=d[j][i]=min(d[i][j],mn);
			}
		}
		cout<<prim()<<endl;
	}else if(k<=5){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) d[i][j]=1e18;
		for(int i=1;i<=m;i++)
			d[e[i].u][e[i].v]=d[e[i].v][e[i].u]=min(d[e[i].u][e[i].v],(long long)e[i].w);
		int ans=prim();
		//cout<<ans<<endl;
		for(int mask=1;mask<(1<<k);mask++){
			for(int i=1;i<=n;i++){
				d[i][i]=0;
				for(int j=i+1;j<=n;j++){
					long long mn=1e18;
					for(int l=1;l<=k;l++)
						if(mask&(1<<(l-1))) mn=min(mn,(long long)t[l][i]+t[l][j]);
					d[i][j]=d[j][i]=min(d[i][j],mn);
				}
			}
			long long cnt=0;
			for(int l=1;l<=k;l++)
				if(mask&(1<<l-1)) cnt+=c[l]; 
			ans=min(ans,prim()+cnt);
			//cout<<ans<<endl;
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++) d[i][j]=1e18;
			for(int i=1;i<=m;i++)
				d[e[i].u][e[i].v]=d[e[i].v][e[i].u]=min(d[e[i].u][e[i].v],e[i].w);
		}
		cout<<ans<<endl;
	}else{
		long long ans=0,cnt=0;
		sort(e+1,e+m+1,cmp);
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=m;i++){
			int u=find(e[i].u),v=find(e[i].v);
			if(u==v) continue;
			ans+=e[i].w;
			cnt++;
			fa[u]=v;
			if(cnt==n-1) break;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) d[i][j]=1e18;
		for(int i=1;i<=m;i++)
			d[e[i].u][e[i].v]=d[e[i].v][e[i].u]=min(d[e[i].u][e[i].v],(long long)e[i].w);
		for(int mask=1;mask<(1<<k-5);mask++){
			for(int i=1;i<=n;i++){
				d[i][i]=0;
				for(int j=i+1;j<=n;j++){
					long long mn=1e18;
					for(int l=1;l<=k;l++)
						if(mask&(1<<(l-1))) mn=min(mn,(long long)t[l][i]+t[l][j]);
					d[i][j]=d[j][i]=min(d[i][j],mn);
				}
			}
			long long cnt=0;
			for(int l=1;l<=k;l++)
				if(mask&(1<<l-1)) cnt+=c[l]; 
			ans=min(ans,prim()+cnt);
			//cout<<ans<<endl;
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++) d[i][j]=1e18;
			for(int i=1;i<=m;i++)
				d[e[i].u][e[i].v]=d[e[i].v][e[i].u]=min(d[e[i].u][e[i].v],e[i].w);
		}
		cout<<ans<<endl;
	}
	return 0;
}
