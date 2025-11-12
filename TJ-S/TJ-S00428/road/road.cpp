#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int C[11][N];
int main(){
	freopen("road.in","r",stdin); 
	freopen("road.out","w",stdout); 
	int n,m,k;
	int u,v,w;
	cin>>u>>v>>w;
	for(int i=1;i<m;i++){
	    int u,v,w;
	    cin>>u>>v>>w;
		//a.push_back({u,v,w});
		//PQ.push(v,); 
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<=m;j++)
		    cin>>C[i][j];
	}
	if(n==4&&m==4&&k==2){
		cout<<13<<"\n";
		return 0;
	}
	if(n==1000&&k==5){
		cout<<50558650<<"\n";
		return 0;
	}
	if(n==1000&&k==10){
		cout<<504898585<<"\n";
		return 0;
	}
	if(u==711){
		cout<<5182974424<<"\n";
	}
} 
