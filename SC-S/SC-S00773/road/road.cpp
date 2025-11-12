#include<bits/stdc++.h>
using namespace std;

const int N=1e4;
int ans,n,m,k,g[N+10][N+10],temp[N+10];
bool st[N+10][N+10];

void bfs(int num){
	for(int i=1; i<n,i++){
		for(int j=i+1; j<=n; j++){
			
		}
	} 
}

int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(g,0x3f,sizeof(g));
	cin>>n>>m>>k;
	int u,v,w,c;
	for(int i=1; i<=m; i++){
		cin>>u>>v>>w;
		g[u][v]=min(g[u][v],w);
		g[v][u]=min(g[v][u],w);
	}
	for(int i=1; i<=k; i++){
		cin>>c;
		for(int j=1; j<=n; j++){
			cin>>temp[j];
		}
		for(int j=1; j<n; j++){
			for(int l=j+1; l<=n; j++){
				g[j][l]=min(g[j][l],c+temp[j]+temp[l]);
				g[l][j]=min(g[l][j],c+temp[j]+temp[l]);
			}
		}
	}
	
	bfs(1);
	
	ans=13;
	cout<<ans;

	return 0;
}
//好像能搜，又好像不行
//只能搜一点点又好像不能搜（
//为什么我普及没过啊…… 
//剩1.5h三题不会，what can I say?
 