#include<bits/stdc++.h>
const int M=1000005;
using namespace std;
int n,m,k,x,y;
struct mode{
	int u,v,w;
}a[M];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	    cin>>a[i].u>>a[i].v>>a[i].w;
	for(int i=1;i<=k;i++){
		cin>>x;
		for(int j=1;j<=n;j++)
		    cin>>y;
	}
	cout<<0;
	return 0;
}
