#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,k,a,b,num;
int x[N][N],y[N][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>a>>b>>num;
		x[a][b]=num;
		x[b][a]=num;
	}  
	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++){
			cin>>y[i][j];
		}
	} 
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			x[i][j]=min(x[i][j],y[i][0]+y[i][j]+y[i][i]);
		}
	}
	return 0;
} 
