#include<bits/stdc++.h>
using namespace std;
const int N=1e3+7,M=1e9+7;
int n,m,k,q[N][N],u,v,w,sum;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j) q[i][j]=M;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		q[v][u]=q[u][v]=w;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(q[i][j]>q[j][k]+q[k][i]) q[i][j]=q[j][k]+q[k][i],q[j][i]=q[j][k]+q[k][i];
				if(q[j][k]>q[i][j]+q[k][i]) q[j][k]=q[i][j]+q[k][i],q[k][j]=q[i][j]+q[k][i];
				if(q[k][i]>q[i][j]+q[j][k]) q[k][i]=q[i][j]+q[j][k],q[i][k]=q[i][j]+q[j][k];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(q[i][j]>q[j][k]+q[k][i]) q[i][j]=q[j][k]+q[k][i],q[j][i]=q[j][k]+q[k][i];
				if(q[j][k]>q[i][j]+q[k][i]) q[j][k]=q[i][j]+q[k][i],q[k][j]=q[i][j]+q[k][i];
				if(q[k][i]>q[i][j]+q[j][k]) q[k][i]=q[i][j]+q[j][k],q[i][k]=q[i][j]+q[j][k];
			}
		}
	}
	for(int i=1;i<n;i++){
		int s=1e9;
		for(int j=i+1;j<=n;j++){
			if(i!=j)
			s=min(s,q[i][j]);
		}
		sum+=s;
	}
	cout<<sum;
	return 0;
}
