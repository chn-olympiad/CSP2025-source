#include <bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w;
}c[100000];
int a[10000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>c[i].u>>c[i].v>>c[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>a[i];
	}
	cout<<n*m;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

