#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[12],a[12][10002],b[10002][10002],u,v,w;
unsigned long long ans=0;
bool vis[10001]={0,1},vi[12]={1,1,1,1,1,1,1,1,1,1,1,1};
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	int num=n-1;
	for(int i=1;i<=m;i++){
		cin >> u >> v >> w;
		b[u][v]=w;
		b[v][u]=w;
	}for(int i=1;i<=k;i++){
		cin >> c[i];
		for(int j=1;j<=n;j++)cin >> a[i][j];
	}while(num){
		int minn[3]={0,1000000001,0};
		for(int i=1;i<=n;i++){
			if(vis[i]){
				for(int j=1;j<=n;j++){
					if(vis[j]==0){
						if(b[i][j]&&b[i][j]<=minn[1]){
							minn[0]=j;
							minn[1]=b[i][j];
							minn[2]=0;
						}for(int l=1;l<=k;l++){
							if(a[l][i]+a[l][j]+c[l]*vi[l]<=minn[1]){
								minn[0]=j;
								minn[1]=a[l][i]+a[l][j]+c[l]*vi[l];
								minn[2]=l;
							}
						}
					}
				}
			}
		}vis[minn[0]]=1;
		ans+=minn[1];
		vi[minn[2]]=0;
		num--;
	}cout << ans;
	return 0;
}
