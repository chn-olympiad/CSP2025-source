#include<iostream>
#include<algorithm>
using namespace std;
const long long INF=1e9+5;
const int N = 1005;
int w[N][N],a[N][N];
bool acs[N][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	int sum=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y>>w[x][y];
		w[y][x]=w[x][y];
		acs[x][y]=1;
		acs[y][x]=1;
	}
	for(int i=1;i<=k;i++){
		int asf;
		cin>>asf;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			int minn=INF;
			for(int u=1;u<=k;u++){
				if(acs[i][j]){
					minn=min(w[i][j],a[u][i]+a[u][j]);
				}
				else minn=min(minn,a[u][i]+a[u][j]);
			}
			sum+=minn;
		}
	}
	cout<<sum;
	return 0;
}
 
