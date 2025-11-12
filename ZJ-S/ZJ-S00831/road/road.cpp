#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=1e3+6;
vector<pair<int,int> >g[N]; 
int w[N];
int r[16][N];
int f[N][(1<<10)];
int b[N][16];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,K;
	cin>>n>>m>>K;
	for(int i=1;i<=m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		g[x].push_back({y,w});
		g[y].push_back({x,w});
	}
	for(int i=1;i<=K;i++){
		cin>>w[i];
		b[0][i]=0x3f3f3f3f3f3f3f3f;
		for(int j=1;j<=n;j++)
		{
			cin>>r[i][j];
			b[j][i]=min(b[j-1][i],r[i][j]);
		}
	}
	memset(f,0x3f,sizeof(f));
	int ans=0x3f3f3f3f3f3f3f3f;
	for(int k=0;k<(1<<K);k++){
		f[1][k]=0;
		for(int i=1;i<=K;i++){
			f[1][k]+=(1&(k>>(i-1)))*(w[i]+r[i][1]);
		}
	}
	for(int i=2;i<=n;i++){
		for(int k=0;k<(1<<K);k++){
			for(int j=0;j<g[i].size();j++){
				f[i][k]=min(f[i][k],f[i-1][k]+g[i][j].second);
			}
			int w=11;
			for(int j=1;j<=K;j++){
				if(1&(k>>(j-1)))
				{
					if(f[i][k]>f[i-1][k]+r[j][i]||(f[i][k]==f[i-1][k]+r[j][i]&&b[i-1][j]-r[j][i]>b[i-1][w]-r[j][w])){
						f[i][k]=f[i-1][k]+r[j][i];
						w=j;
					}
				}
			}
			for(int j=1;j<=K;j++){
				if((1&(k>>(j-1)))&&j!=w&&r[j][i]<b[i-1][j])
				{
					f[i][k]-=b[i-1][j]-r[j][i];
				}
			}
		}
	}
	for(int i=0;i<(1<<K);i++){
		ans=min(ans,f[n][i]);
	}
	cout<<ans;
	return 0;
}