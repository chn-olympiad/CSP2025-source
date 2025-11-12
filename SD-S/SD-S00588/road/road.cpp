#include<bits/stdc++.h>
using namespace std;
int f[5005][5005],c[15],n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=0x3f3f3f3f;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		f[u][v]=f[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			f[i][j]=min(f[i][j],w);
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(f[i][j]!=0x3f3f3f3f)ans+=f[i][j];
	cout<<(ans>>1);
	return 0;
}
