#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
int x,y,c,z[10010],zz;
int kk[10010][10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>c;
		kk[x][y]=c+1;
		kk[y][x]=c+1;
	}
	for(int i=1;i<=k;i++){
		cin>>zz;
		for(int j=1;j<=n;j++){
			cin>>z[j];
		}
		for(int j=1;j<=n;j++){
			for(int u=1;u<=n;u++){
				if(j==u) continue;
				if(kk[j][u]==0){
					kk[j][u]=z[j]+z[u]+zz;
				}else{
					kk[j][u]--;
					kk[j][u]=min(kk[j][u],z[j]+z[u]+zz);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		int minn=99999999;
		for(int j=1;j<=n;j++){
			if(i!=j) minn=min(minn,kk[i][j]);
		}
		ans+=minn;
	}
	cout<<ans;
	return 0;
}
