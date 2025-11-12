#include<bits/stdc++.h>
using namespace std;
const long long int X=100009;
const int xy=999999;

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	long long sum[X]={0},maxx=0,mai=0,ans,dis[X]={0};
	long long u[xy],v[xy],w[xy],c[xy],a[16][xy];
	for(int i=1;i<=n;i++){
		cin>>u[i]>>v[i]>>w[i];
		sum[u[i]]++;
		sum[v[i]]++;
		mai=max(u[i],mai);
		mai=max(v[i],mai);
	} 
	for(int j=1;j<=k;j++){
		cin>>c[j];
		for(int i=1;i<=m;i++){
			cin>>a[j][i];
		}
	}
	for(int i=1;i<=mai;i++){
		maxx=max(maxx,sum[i]);
	}
	for(int ix=1;ix<=n;ix++){
		if(u[ix]==sum[maxx]||u[ix]==sum[maxx]){
			ans+=w[ix]; 
			dis[ix]=1;
		}
	}
	for(long long ix=1;ix<=n;ix++){
			if(u[ix]!=sum[maxx]&&u[ix]!=sum[maxx]){
				long long minn=INT_MAX;
				for(int j=1;j<=n;j++){
					if(dis[u[j]]==1||dis[v[j]]==1){
						minn=min(minn,w[j]);
					}
				}
				long long cnt=0;
				if(ix<=k){
					cnt=c[ix];
					for(int i=1;i<n;i++){
						for(int j=i;j<=n;j++){
							if(a[ix][i]>a[ix][j]){
								swap(a[ix][i],a[ix][j]);
							}
						}
					}
					cnt=min(cnt,a[ix][1]);
					ans+=min(minn,cnt);	
				}
				else{
					ans+=minn;
				}
			}
		}
	cout<<ans;
	return 0;
}
