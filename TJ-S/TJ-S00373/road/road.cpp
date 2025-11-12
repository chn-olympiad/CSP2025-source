#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const long long maxn=10000;
int a[maxn][maxn]={},u,v,w,n,m,k;
int b[11][maxn]={};
int vis[maxn]={};
int ans=1000000;
int tem=0;
/*4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4*/
int check(){
	for(int i=1;i<=n;i++){
		if(vis[i]==0)
		return 1;
		
	}
	return 0;
}
int dfs(int p){
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
		vis[i]=1;
		tem+=a[p][i];
	//	cout<<i<<" ";
		dfs(i);
		
		if(check()==0){
		//cout<<tem<<endl;
		if(tem<ans)
		ans=tem;}
		vis[i]=0;
		tem-=a[p][i];
		//cout<<"p"<<p<<"i"<<i<<endl;
		
		}
		
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
	}
	for(int i=0;i<k;i++){
		cin>>b[i][0];
		for(int j=1;j<=m;j++){
			cin>>b[i][j];
		}
		
	}
	
	
	for(int i=0;i<k;i++){
		for(int j=1;j<=m;j++){
			for(int k=j+1;k<=m;k++){
				if(a[j][k]==0){
					a[j][k]=b[i][0]+b[i][k]+b[i][j];
					
				}
				else 
				a[j][k]=min(a[j][k],b[i][0]+b[i][k]+b[i][j]);
				a[k][j]=a[j][k];
			}
		}
	}/*for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}*/
	vis[1]=1;
    dfs(1);
    cout<<ans;
	
	
	return 0;
}
