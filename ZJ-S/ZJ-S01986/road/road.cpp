#include<bits/stdc++.h>
using namespace std;
int n,m,k,s,ii,a[10005][10005],u,v[10005],w,mn=2e9,mnx,mny,vis[10005];
struct bian{
	int xid,yid,p;
}arr[2000000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(a,0x3f,sizeof(a));
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>u>>v[0]>>w;
		a[u][v[0]]=min(a[u][v[0]],w);
		a[v[0]][u]=min(a[v[0]][u],w);
		if(a[v[0]][u]<mn){
			mn=a[v[0]][u];
			mnx=u;
			mny=v[0];
		}
	}
	for(int i=1;i<=k;i++){
		cin>>u;
		for(int j=1;j<=n;j++){
			cin>>v[j];
		}
		for(int j=1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				a[j][k]=min(u+v[j]+v[k],a[j][k]);
				a[k][j]=min(u+v[j]+v[k],a[k][j]);
				if(a[j][k]<mn){
					mn=a[j][k];
					mnx=j;
					mny=k;
				}
			}
		}
	}
	mn=2e9;
	vis[mnx]=1;
	vis[mny]=1;
	s+=a[mnx][mny];
	for(int i=2;i<n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(vis[j]==1&&vis[k]==0&&a[j][k]<mn){
					mn=a[j][k];
					mnx=k,mny=j;
				}
			}
		}
		vis[mnx]=1;
		s+=a[mnx][mny];
		mn=2e9;
	}
	cout<<s;
}
