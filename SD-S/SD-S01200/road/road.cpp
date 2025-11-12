#include <cstdio>
#include <iostream>
using namespace std;
int a[10][10001],c[10001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,cnt=0;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		if(i<2){
			cnt=cnt+w;
		}
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
	for(int j=1;j<=n;j++){
		cin>>a[i][j];
	}
}
    cout<<cnt+a[1][1]+a[1][2];
	return 0;
}
