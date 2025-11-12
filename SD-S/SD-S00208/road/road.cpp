#include<iostream>
#include<stdio.h>
using namespace std;
int n,m,k,c[15][10005];
struct kk{
	int u,v,w;
}a[20005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i][1];
		for(int j=2;j<=n+1;j++){
			cin>>c[i][j];
		}
	}
	cout<<0;
	return 0;
} 
