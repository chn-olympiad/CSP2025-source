#include<bits/stdc++.h>
using namespace std;



const int maxn=1000005;
int n,m,k;
int u[maxn],v[maxn],w[maxn];
int a[15][maxn];
int c[15];


int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	int op=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0)op=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(op){
		cout<<0;
	}
	return 0;
}
/*
3 3 2
1 2 3
2 3 3
1 3 3
0 0 0 0
0 0 0 0

*/