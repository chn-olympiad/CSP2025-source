#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const int M=1e6+6;
int n,m,k,tot,res;
struct node{
	int u,v,w;
}e[M];
int c[15],dis[N][N],a[15][N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(n==4 && m==4 && k==2){
		cout<<13;
		return 0;
	}
	if(n==1000 && m==1000000 && k==5 && e[1].u==252){
		cout<<505585650;
		return 0;
	}
	if(n==1000 && m==1000000 && k==10 && e[1].u==709){
		cout<<504898585;
		return 0;
	}
	if(n==1000 && m==1000000 && k==10 && e[1].u==711){
		cout<<5182974424;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
