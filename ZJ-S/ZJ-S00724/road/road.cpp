#include<bits/stdc++.h>
using namespace std;
int mp[10010][10010];
int b[10010];
int d[100000010];
bool cmp[10010][10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int u,v,w;
	memset(mp,0x3f,sizeof(mp));
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		mp[u][v]=w;
		mp[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>w;
		for(int j=1;j<=n;j++){
			cin>>b[j];
		}
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(k!=j){
					mp[j][k]=min(mp[j][k],w+b[k]+b[j]);
				}
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(cmp[i][j]==false&&i!=j){
				d[++cnt]=mp[i][j];
				cmp[i][j]=true;
				cmp[j][i]=true;
			}
		}
	}
	sort(d+1,d+1+cnt);
	long long ans=0;
	for(int i=1;i<=n-1;i++){
		ans+=d[i];
	}
	cout<<ans;
	return 0;
}
