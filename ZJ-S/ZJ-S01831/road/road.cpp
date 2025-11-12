#include<bits/stdc++.h>
using namespace std;
struct line{
	long long u,v,w;
	bool operator <(const line& x)const {
		return x.w<w;
	}
};
vector<line> point;
long long ww[1000001],fa[1000001],dis[10011][10011],vis[11];
long long find(long long xx){
	if(fa[xx]==xx)return xx;
	return fa[xx]=find(fa[xx]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;cin>>n>>m>>k;
	long long ans=0;
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=n+k;i++){
		for(int j=i;j<=n+k;j++){
			dis[i][j]=1e18;
			dis[j][i]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		dis[u][v]=min(dis[u][v],w);
		dis[v][u]=dis[u][v];
	}
	for(int i=1;i<=k;i++){
		cin>>ww[i];
		for(int j=1;j<=n;j++){
			long long x;cin>>x;
			dis[j][i+n]=min(dis[j][i+n],x+ww[i]);
			dis[i+n][j]=dis[j][i+n];
		}
	}
	for(int i=1;i<=n+k;i++){
		for(int j=i+1;j<=n+k;j++){
			if(i>n&&j>n)continue;
			point.push_back({i,j,dis[i][j]});
		}
	}
	sort(point.begin(),point.end());
	reverse(point.begin(),point.end());
	for(int i=0;i<point.size();i++){
		long long aa=find(point[i].u),bb=find(point[i].v);
		if(aa!=bb){
			fa[aa]=bb;
			ans+=point[i].w;
			if(point[i].u>n&&!vis[point[i].u-n]){
				ans+=ww[point[i].u];	
				vis[point[i].u-n]=1;
			}
			if(point[i].v>n&&!vis[point[i].v-n]){
				ans+=ww[point[i].v];	
				vis[point[i].v-n]=1;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}