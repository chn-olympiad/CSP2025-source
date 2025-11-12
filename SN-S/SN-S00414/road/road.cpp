#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,m,k;
struct node{
	int v,w;
};
int e[N][N];
int c[15];
int a[15][N];
int sum[N];
int ans=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road1.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[u][v]=w;
		e[v][u]=w;
		ans+=w;
	}
	int f=1;
	for(int j=1;j<=k;j++){
		cin>>c[j];
		if(c[j]!=0) f=0;
		for(int i=1;i<=n;i++){
			cin>>a[j][i]; 
			if(a[j][i]!=0) f=0;
		}
		for(int i=1;i<=n;i++){
			for(int k=1;k<=n;k++){
				int b=c[j]+a[j][i]+a[j][k];
				if(b<e[i][k]){
					ans-=e[i][k]-b;
				}
			}
		}
	}
	if(f==1){
		cout<<0;
		return 0;
	}
	cout<<ans<<"\n";
	return 0;
}
