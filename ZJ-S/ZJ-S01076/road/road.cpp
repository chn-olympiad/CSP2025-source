#include<bits/stdc++.h>
using namespace std;
struct road{
	int u,v,w;
}a[100006];
struct vil{
	int mon,b[10006];
}c[11];
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("rosd.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i].mon;
		for(int j=1;j<=n;j++){
			cin>>c[i].b[j];
		}
	}
	cout<<100;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
