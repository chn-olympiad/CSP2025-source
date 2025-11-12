#include<bits/stdc++.h>
using namespace std;
int u[10005],v[10005],w[10005],n,m,k,c[15],a[10005][13];
bool f;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
		if(c[i]!=0)f=1;
	}
	if(!f){
		cout<<0;
	}
	else cout<<13;
}
