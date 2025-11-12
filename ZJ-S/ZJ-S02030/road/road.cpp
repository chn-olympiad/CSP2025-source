#include<bits/stdc++.h>
using namespace std;
long long ans=0;
int n,x,t,k,m,u,v,w,fl[20];
vector<int  > c[10010];
map<int,map<int,int> >g,f;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	c=m+k*n;
	for(int i=1;i<=c;i++)for(int j=1;j<=c;j++)f[i][j]=1000000001;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		g[u][v]=w;g[v][u]=w;
		f[u][v]=min(f[u][v],w);
		f[v][u]=min(f[v][u],w);
		//g[u].push_back({v,w});
	}
	
	if(k==0){
	for(int i=1;i<=n;i++){
		for(int a=1;a<=n;a++){
			for(int b=1;b<=n;b++){
				f[a][b]=min(f[a][b],f[a][i]+f[i][b]);
			}
		}
	}
	
	for(int i=2;i<=n;i++){
		ans+=f[i-1][i];
	}
	
		cout<<ans;
		
		
		return 0;
	}
	
	
	fl[0]=0;
	for(int ii=1;ii<=k;ii++){
		cin>>fl[ii];
		fl[ii]+=fl[ii-1];
		for(int i=1;i<=n;i++){
			cin>>w;
			g[i][n+ii]=w;g[n+ii][i]=w;
			f[n+ii][i]=min(f[n+ii][i],w);
			f[i][n+ii]=min(f[i][n+ii],w);
			//g[u].push_back({v,w});	
		}
		
	}
	int nn=n+k;
	ans=fl[k];
	//cout<<ans<<"------\n";
	for(int i=1;i<=nn;i++){
		for(int a=1;a<=nn;a++){
			for(int b=1;b<=nn;b++){
				f[a][b]=min(f[a][b],f[a][i]+f[i][b]);
			}
		}
	}for(int a=1;a<=n;a++){
			for(int b=1;b<=n;b++){
				ans+=f[a][b];
			}
		}
		cout<<ans;
	return 0;
}

/*
4 4 0 1 2 100 2 4 100 4 3 100 1 3 100 
4 4 1 1 2 100 2 4 100 4 3 100 1 3 100 0 1 1 1 1

*/
