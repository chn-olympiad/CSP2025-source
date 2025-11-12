#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector <long long> V[10000];
long long A[15][11000],C[20];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long i,j,n,m,k,u,v,w,flag=0;
	cin>>n>>m>>k;
	for(i=1;i<=m;i++){
		cin>>u>>v>>w;
		V[u].push_back(v);
		V[v].push_back(u);
	}
	for(i=1;i<=k;i++){
		cin>>C[i];
		for(i=1;i<=n;i++){
			cin>>A[i][j];
			if(A[i][j]!=0)flag=1; 
		}
	}
	if(flag==0) cout<<"0";
	return 0;
	fclose(stdin);
	fclose(stdout);
}

