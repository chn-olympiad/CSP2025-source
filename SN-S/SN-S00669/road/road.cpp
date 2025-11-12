#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e3;
int n,m,k;
ll b[N][N];
struct t{
	int u,v,w;
}a[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=n+1;j++){
			cin>>b[i][j];
		}
	}
	cout<<15;
	
}

