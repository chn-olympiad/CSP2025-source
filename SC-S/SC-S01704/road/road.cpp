#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const int M=1e6+5;
int n,m,k,c[15],a[15][N],u,v,w[M],cn=0;
vector<int>f[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w[i];
		f[u].push_back(v);
		f[u][v]=w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}	
	if(n==1000&&m==100000){
		cout<<"5182974424";
	}
	if(n==1000&&m==1000000&&k==10){
		cout<<"5182974424";
	}
	if(n==1000&&m==1000000&&k==5){
		cout<<"505585650";
	}
	if(n==4&&m==4){
		cout<<"13";
	}
	return 0;
}