#include <bits/stdc++.h>
using namespace std;
const int N=1005,inf=1<<29;
int n,m,k;
long long ans;
struct edge{
	int net,from,to,val;
}e[N*3000];
struct point{
	int x,y,val;
};
bool operator<(const point &a,const point &b){
	return a.val>b.val;
}
int head[N],tot;
void add(int u,int v,int w){
	e[++tot].from=u;
	e[tot].net=head[u];
	e[tot].to=v;
	e[tot].val=w;
	head[u]=tot;
}
long long dis[N][N],cf[N];
int root[N],vis[N];
int find(int x){
	if(root[x]==x) return x;
	return root[x]=find(root[x]);
}
void join(int x,int y){
	int xx=find(x),yy=find(y);
	root[xx]=yy;
}
bool viss[N][N];
priority_queue <point> qq;
void kru(){
	while(qq.size()){
		point tt=qq.top();
		qq.pop();
		int xx=tt.x,yy=tt.y,v=tt.val;
		if(find(xx)==find(yy)) continue;
		join(xx,yy);
		dis[xx][yy]=v;dis[yy][xx]=v;
		viss[xx][yy]=1;viss[yy][xx]=1;
		ans+=v;
	}
} 
int a[N][N],c[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) root[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w; 
		qq.push({u,v,w});
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=inf;
		}
		dis[i][i]=0;
	}
	kru();
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			for(int l=1;l<=n;l++){
//				if(dis[i][j]>dis[i][l]+dis[l][j]){
//					dis[i][j]=dis[i][l]+dis[l][j];
//				}
//			}
//		}
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int l=1;l<=n;l++){
				if(dis[i][j]>abs(dis[i][l]-dis[l][j])){
					if(!viss[i][j]&&viss[i][l]&&viss[l][j])
					dis[i][j]=abs(dis[i][l]-dis[l][j]);
				}
			}
		}
	}
	for(int i=1+n;i<=1+n+k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}//dj
//	dj(1);
//	
//	for(int l=n+1;l<=n+1+k;l++){
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;j<=n;j++){
//				if(a[l][i]+a[l][j]<dis[i][j]){
//					if(vis[l]){
//						ans-=dis[i][j];
//						ans+=a[l][i]+a[l][j];
//						dis[i][j]=a[l][i]+a[l][j];
//					}else{
//						if(a[l][i]+a[l][j]+c[l]<=dis[i][j]){
//							vis[l]=1;
//							ans-=dis[i][j];
//							ans+=a[l][i]+a[l][j];
//							ans+=cf[l];
//							dis[i][j]=a[l][i]+a[l][j];
//						}else{
//							cf[l]+=dis[i][j]-a[l][i]+a[l][j];
//							if(cf[l]>=dis[i][j]){
//								cf[l]=0;
//								ans-=(cf[l]-dis[i][j]);
//								vis[l]=1;
//							}
//							
//						}
//					}
//				}
//			}
//		}		
//	}
//	for(int l=n+1;l<=1+n+k;l++){
//		ans+=cf[l];
//	}
	cout<<ans;
	return 0; 
} 
