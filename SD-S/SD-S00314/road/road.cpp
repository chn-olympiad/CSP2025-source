#include<bits/stdc++.h>
using namespace std;
int ma[10000][10000];
bool vis[100000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k2;
	cin>>n>>m>>k2;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		ma[a][b]=c;
		ma[b][a]=c;
	}
	int k[10000];
	k[1]=1;
	int k1=1;
	vis[1]=true;
	int num=1;
	int ans=0;
	while(num<n){
		int node1,node2,minn=1e8;
		for(int i=1;i<=k1;i++){
			for(int j=1;j<=n;j++){
				if(k[i]==j||vis[j]==true||ma[k[i]][j]==0){
					continue;
				}
				if(ma[k[i]][j]<minn){
					minn=ma[k[i]][j];
					node1=k[i];
					node2=j;
				}
			}
		}
		ans+=ma[node1][node2];
		vis[node2]=true;
		k1++;
		k[k1]=node2;
		num++;
	}
	cout<<ans;
}
