#include<bits/stdc++.h>
using namespace std;
int const N=1e6+10;
int const M=1e4+10;
struct node{
	int u,v,w;
}g[N];
int ca[15][M],c[15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int sum2=0;
	for(int i=1;i<=m;i++){cin>>g[i].u>>g[i].v>>g[i].w; sum2+=g[i].w; }
	if(k==0){
		cout<<sum2;
		return 0;
	} 
	int sum=INT_MAX;
	for(int i=1;i<=k;i++){
		int num=0;
		cin>>c[i];
		num+=c[i];
		for(int j=1;j<=n;j++) {cin>>ca[i][j]; num+=ca[i][j];}
		sum=min(num,sum);
	}
	cout<<min(sum,sum2);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
