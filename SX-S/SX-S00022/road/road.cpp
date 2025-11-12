#include<bits/stdc++.h>
using namespace std;
struct node{
	int city;
	int pride;
}a[10014];
int mapp[1013][1013];
int zp[1013][1013];
int ka[15][10014];
int n,m,k;
void add_edge(int u,int v,int w){
	mapp[u][v]=w;
	mapp[v][u]=w;
	zp[u][v]=w;
	zp[v][u]=w;
}void Floyd(){
	for(int t=1;t<=n+k;t++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(mapp[i][j])mapp[i][j]=min(mapp[i][j],mapp[i][t]+mapp[t][j]),zp[i][j]=0;
				else mapp[i][j]=mapp[i][t]+mapp[t][j];
				mapp[j][i]=mapp[i][j];
				zp[j][i]=0;
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add_edge(u,v,w);
	}bool outflag=false;
	for(int i=1+n;i<=k+n;i++){
		bool inflag=true;
		int c;
		cin>>c;
		if(c!=0)inflag=false;
		for(int j=1;j<=n;j++){
			cin>>ka[i][j];
			if(ka[i][j]!=0)inflag=false;
			if(mapp[i][j]==0)add_edge(i,j,ka[i][j]+c);
			else add_edge(i,j,min(mapp[i][j],ka[i][j]+c));
		}if(inflag){
			outflag=true;
		}
	}if(outflag){
		cout<<0;
		return 0;
	}
	Floyd();
	long long ans=0;
	for(int i=1;i<=n+k;i++){
		for(int j=i+1;j<=n+k;j++){
			ans+=zp[i][j];
		}
	}cout<<ans<<endl;
	return 0;
}